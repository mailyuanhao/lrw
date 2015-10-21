#ifndef _CMD_IOPORT_H_
#define _CMD_IOPORT_H_
#include "cmdimp.h"

//inb class.
class do_inb :
	public do_read
{
public:
	bool cmd(u16 portAddr, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("I");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("In Port Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"I <port>			Read I/O port byte (8-bit) data";
		return outstream;
	}
};

class do_outb :
	public do_write
{
public:
	bool cmd(u16 portAddr, u8 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("O");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Out Port Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"O <port> <data>			Write I/O port byte (8-bit) data";
		return outstream;
	}
};

class do_inw :
	public do_read
{
public:
	bool cmd(u16 portAddr, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("I16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("In Port Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"I16 <port>			Read I/O port word (16-bit) data";
		return outstream;
	}
};

class do_outw :
	public do_write
{
public:
	bool cmd(u16 portAddr, u16 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("O16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Out Port Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"O16 <port> <data>			Write I/O port word (16-bit) data";
			return outstream;
	}
};

class do_inl :
	public do_read
{
public:
	bool cmd(u16 portAddr, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("I32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("In Port Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"I32 <port>			Read I/O port dword (32-bit) data";
		return outstream;
	}
};

class do_outl :
	public do_write
{
public:
	bool cmd(u16 portAddr, u32 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("O32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Out Port Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"O32 <port> <data>			Write I/O port dword (32-bit) data";
		return outstream;
	}
};

#endif //_CMD_IOPORT_H_
