#ifndef _CMD_PCI_H_
#define _CMD_PCI_H_

#include "cmdimp.h"

class do_rpcib :
	public do_read
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("RPCI");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read PCI Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"RPCI <bus#> <dev#> <fun#> <offset>			Read PCI byte (8-bit) data";
		return outstream;
	}
};

class do_rpciw :
	public do_read
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("RPCI16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read PCI Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"RPCI16 <bus#> <dev#> <fun#> <offset>			Read PCI Word (16-bit) data";
		return outstream;
	}
};

class do_rpcil :
	public do_read
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("RPCI32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Read PCI Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"RPCI <bus#> <dev#> <fun#> <offset>			Read PCI32 Dword (32-bit) data";
		return outstream;
	}
};

class do_wpcib :
	public do_write
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, u8 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("WPCI");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write PCI Byte");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"WPCI <bus#> <dev#> <fun#> <offset> <value>	\
		   Write PCI byte (8-bit) data";
		return outstream;
	}
};

class do_wpciw :
	public do_write
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, u16 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("WPCI16");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write PCI Word");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"WPCI16 <bus#> <dev#> <fun#> <offset> <value>	\
				   Write PCI word (16-bit) data";
		return outstream;
	}
};

class do_wpcil :
	public do_write
{
public:
	bool cmd(u8 bus, u8 dev, u8 func, u8 offset, u32 value, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("WPCI32");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Write PCI Dword");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"WPCI32 <bus#> <dev#> <fun#> <offset> <value>	\
				   Write PCI dword (32-bit) data";
		return outstream;
	}
};

#endif //_CMD_PCI_H_
