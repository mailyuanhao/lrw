#ifndef _CMD_MEM_H_
#define _CMD_MEM_H_

#include "cmdimp.h"

class do_rmemb :
	public do_read
{
public:
	bool cmd(ptrint addr, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("R8");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read MEM Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"R8 <addr#> 			Read MEM byte (8-bit) data";
		return outstream;
	}
};

class do_rmemw :
	public do_read
{
public:
	bool cmd(ptrint addr, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("R16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read MEM Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"R16 <addr#> 		Read MEM Word (16-bit) data";
		return outstream;
	}
};

class do_rmeml :
	public do_read
{
public:
	bool cmd(ptrint addr,  std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("R32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read MEM Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"R32 <bus#> <dev#> <fun#> <offset>			Read MEM32 Dword (32-bit) data";
		return outstream;
	}
};

class do_wmemb :
	public do_write
{
public:
	bool cmd(ptrint addr, u8 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("W8");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write MEM Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"W8 <bus#> <dev#> <fun#> <offset> <value>	\
		   Write MEM byte (8-bit) data";
		return outstream;
	}
};

class do_wmemw :
	public do_write
{
public:
	bool cmd(ptrint addr, u16 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("W16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write MEM Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"W16 <bus#> <dev#> <fun#> <offset> <value>	\
				   Write MEM word (16-bit) data";
		return outstream;
	}
};

class do_wmeml :
	public do_write
{
public:
	bool cmd(ptrint addr, u32 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("W32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write MEM Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"W32 <bus#> <dev#> <fun#> <offset> <value>	\
				   Write MEM dword (32-bit) data";
		return outstream;
	}
};

#endif //_CMD_MEM_H_
