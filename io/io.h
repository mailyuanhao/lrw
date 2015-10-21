#ifndef _IO_H_
#define _IO_H_
#include "datatype.h"
#include "single.h"
#include "config_lrw.h"
//是否需要再添加個間接層來實現driver的動態切換？

const u32 BYTE_S = 1;
const u32 WORD_S = 2;
const u32 DWORD_S = 4;

class DoIO
{
	friend class SingletonHolder<DoIO>;
public:
	bool init();

	u8 io_inb_p(u16 paddr);
	u16 io_inw_p(u16 paddr);
	u32 io_inl_p(u16 paddr);

	void io_outb_p(u8 v, u16 paddr);
	void io_outw_p(u16 v, u16 paddr);
	void io_outl_p(u32 v, u16 paddr);

	bool Rpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32& value);
	bool Wpci(u32 bus, u32 dev, u32 func, u32 off, u32 size, u32 value);

	bool ReadMem(unsigned long base, size_t len, void* buff);
	bool WriteMem(unsigned long base, size_t len, void* buff);
	const ErrorLog& getError()
	{
		return m_err;
	}

private:
	u32 PciAddr(u32 bus, u32 dev, u32 func, u32 offset);

private:
	DoIO(){}
	DoIO(const DoIO&);
	DoIO& operator = (const DoIO&);
	ErrorLog m_err;
};

typedef SingletonHolder<DoIO> IO;

#endif //_IO_H_
