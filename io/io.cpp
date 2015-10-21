#include "io.h"
#ifdef	IO_DEBUG
#include <iostream>
bool DoIO::init()
{
	return true;	
}

u8 DoIO::io_inb_p(u16 paddr)
{
	std::cout<<"inb "<<paddr<<std::endl;
	return 147;
}

u16 DoIO::io_inw_p(u16 paddr)
{
	std::cout<<"inw "<<paddr<<std::endl;
	return 321;
}

u32 DoIO::io_inl_p(u16 paddr)
{
	std::cout<<"inl "<<paddr<<std::endl;
	return 123;
}

void DoIO::io_outb_p(u8 v, u16 paddr)
{
	std::cout<<"outb value:"<<v<<" addr:"<<paddr<<std::endl;
}

void DoIO::io_outw_p(u16 v, u16 paddr)
{
	std::cout<<"outw value:"<<v<<" addr:"<<paddr<<std::endl;
}

void DoIO::io_outl_p(u32 v, u16 paddr)
{
	std::cout<<"outl value:"<<v<<" addr:"<<paddr<<std::endl;
}

#define PCI_ADDR_PORT	0xcf8
#define PCI_DATA_PROT	0xcfc

bool DoIO::Rpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32& value)
{
	std::cout<<"rpci "<<bus<<" "<<dev<<" "<<func<<" "<<off<<" "<<size<<std::endl;
	return true;
}

bool DoIO::Wpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32 value)
{
	m_err.clear();
	std::cout<<"wpci "<<bus<<" "<<dev<<" "<<func<<" "<<off<<" "<<size<<" "<<value<<std::endl;
	m_err.push_back("ERRRRRRRRRRRRRRR");
	m_err.push_back("HHHHHHHHHHHHHH");
	return false;
}

#else
#include <sys/io.h>
bool DoIO::init()
{
	m_err.clear();
	if (iopl(3) != 0)
	{
		m_err.push_back("iopl(3) failed");
		return false;
	}
	return true;	
}
#include <iostream>
u8 DoIO::io_inb_p(u16 paddr)
{
	return inb_p(paddr);
}

u16 DoIO::io_inw_p(u16 paddr)
{
	return inw_p(paddr);
}

u32 DoIO::io_inl_p(u16 paddr)
{
	return inl_p(paddr);
}

void DoIO::io_outb_p(u8 v, u16 paddr)
{
	outb_p(v, paddr);
}

void DoIO::io_outw_p(u16 v, u16 paddr)
{
	outw_p(v, paddr);
}

void DoIO::io_outl_p(u32 v, u16 paddr)
{
	outl_p(v, paddr);
}

#define PCI_ADDR_PORT	0xcf8
#define PCI_DATA_PROT	0xcfc

bool DoIO::Rpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32& value)
{
	m_err.clear();
	u32 pciAddr = PciAddr(bus, dev, func, off);
	if (pciAddr == 0)
	{
		return false;
	}

	union
	{
		u32 m_u32;
		u16 m_u16[2];
		unsigned char m_u8[4];
	}temp;


	io_outl_p(pciAddr, PCI_ADDR_PORT);
	temp.m_u32 = io_inl_p(PCI_DATA_PROT);

	switch(size)
	{
	case BYTE_S:
		value = temp.m_u8[off & 3];
		break;

	case WORD_S:
		value = temp.m_u16[(off >> 1) & 1];
		break;

	case DWORD_S:
	default:
		value = temp.m_u32;
		break;
	}

	return true;
}

bool DoIO::Wpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32 value)
{
	m_err.clear();

	u32 pciAddr = PciAddr(bus, dev, func, off);
	if (pciAddr == 0)
	{
		return false;
	}

	io_outl_p(pciAddr, PCI_ADDR_PORT);

	u16 PortAddr = PCI_DATA_PROT;
	switch(size)
	{
	case BYTE_S:
		PortAddr += (off & 3);
		io_outb_p((u8)value, PortAddr);
		break;

	case WORD_S:
		PortAddr += (off & 2);
		io_outw_p((u16)value, PortAddr);
		break;

	case DWORD_S:
	default:
		io_outl_p(value, PortAddr);
		break;
	}

	return true;
}

u32 DoIO::PciAddr(u32 bus, u32 dev, u32 func, u32 offset)
{
	m_err.clear();
	if (bus > 255 || dev > 31 || func > 7 || offset > 255)
	{
		m_err.push_back("The bus range is 0 - 255, dev range is 0 - 31,\
						func range is 0 - 7, offset range is 0 -255");
		return 0;
	}

	return (0x80000000 | ((bus & 0x0ff) << 16) 
		| ((dev & 0x1F) << 11) 
		| ((func & 0x07) << 8)
		| (offset & 0xFC));
}
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
int myread(int fd, u8* buf, size_t count)
{
	ssize_t r = 1;
	size_t r2 = 0;

	while(r2 != count && r != 0)
	{
		r = read(fd, buf + r2, count - r2);
		if (r == -1)
		{
			if (errno != EINTR)
			{
				return -1;
			}
		}else
		{
			r2 += r;
		}
	}

	if (r2 != count)
	{
		return -1;
	}
	return 0;
}
int mywrite(int fd, u8* buf, size_t count)
{
	ssize_t r = 1;
	size_t r2 = 0;

	while(r2 != count && r != 0)
	{
		r = write(fd, buf + r2, count - r2);
		if (r == -1)
		{
			if (errno != EINTR)
			{
				return -1;
			}
		}else
		{
			r2 += r;
		}
	}

	if (r2 != count)
	{
		return -1;
	}
	return 0;
}
bool DoIO::ReadMem(unsigned long base, size_t len, void* buff)
{
	void* p;
	int fd;
#ifdef USE_MMAP
	size_t mmoffset;
	void* mmp;
#endif

	if((fd = open(DEFAULT_MEM_DEV, O_RDONLY)) == -1)	
	{
		//log here
		m_err.push_back("ReadMem Enrror");
		m_err.push_back(DEFAULT_MEM_DEV);
		goto RETURN_FALSE;
	}

#ifdef USE_MMAP
#ifdef _SC_PAGESIZE
	mmoffset = base % sysconf(_SC_PAGESIZE);
#else
	mmoffset = base % getpagesize();
#endif /*_SC_PAGESIZE*/
	mmp = mmap(0, mmoffset + len, PROT_READ, MAP_SHARED, fd, base - mmoffset);
	if (mmp == MAP_FAILED)
	{
		//log here
		goto RETURN_CLOSE_FALSE;		
	}

	memcpy(buff, (u8*)mmp + mmoffset, len);

	if (munmap(mmp, mmoffset + len) == -1)
	{
		//log here
		goto RETURN_CLOSE_FALSE;
	}
#else
	if (lseek(fd, base, SEEK_SET) == -1)
	{
		//log here
		goto RETURN_CLOSE_FALSE;
	}

	if (myread(fd, (u8*)buff, len) == -1)
	{
		goto RETURN_CLOSE_FALSE;
	}
#endif
	close(fd);
	return true;

RETURN_CLOSE_FALSE:
	close(fd);
RETURN_FALSE:
	m_err.push_back("ReadMem Error");
	return false;
}
bool DoIO::WriteMem(unsigned long base, size_t len, void* buff)
{

	void* p;
	int fd;
#ifdef USE_MMAP
	size_t mmoffset;
	void* mmp;
#endif

	if((fd = open(DEFAULT_MEM_DEV, O_WRONLY)) == -1)	
	{
		//log here
		goto RETURN_FALSE;
	}

#ifdef USE_MMAP
#ifdef _SC_PAGESIZE
	mmoffset = base % sysconf(_SC_PAGESIZE);
#else
	mmoffset = base % getpagesize();
#endif /*_SC_PAGESIZE*/
	mmp = mmap(0, mmoffset + len, PROT_WRITE, MAP_SHARED, fd, base - mmoffset);
	if (mmp == MAP_FAILED)
	{
		//log here
		goto RETURN_CLOSE_FALSE;		
	}

	memcpy((u8*)mmp + mmoffset, buff, len);

	if (munmap(mmp, mmoffset + len) == -1)
	{
		//log here
		goto RETURN_CLOSE_FALSE;
	}
#else
	if (lseek(fd, base, SEEK_SET) == -1)
	{
		//log here
		goto RETURN_CLOSE_FALSE;
	}

	if (mywrite(fd, (u8*)buff, len) == -1)
	{
		goto RETURN_CLOSE_FALSE;
	}
#endif
	close(fd);
	return true;

RETURN_CLOSE_FALSE:
	close(fd);
RETURN_FALSE:
	return false;
}
#endif
