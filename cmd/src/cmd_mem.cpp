#include "cmd_mem.h"
#include "io/io.h"

bool do_rmemb::cmd(ptrint addr, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().ReadMem(addr, 1, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}else
	{
		outstream<<value<<std::endl;
	}

	return true;
}
INSERT_CMD_PARA1(do_rmemb, ptrint);

bool do_rmemw::cmd(ptrint addr, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().ReadMem(addr, 2, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}else
	{
		outstream<<value<<std::endl;
	}

	return true;
}
INSERT_CMD_PARA1(do_rmemw, ptrint);

bool do_rmeml::cmd(ptrint addr, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().ReadMem(addr, 4, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}else
	{
		outstream<<value<<std::endl;
	}

	return true;
}
INSERT_CMD_PARA1(do_rmeml, ptrint);

bool do_wmemb::cmd(ptrint addr, u8 value,  std::ostream& outstream)
{
	if (!IO::Instance().WriteMem(addr, 1, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA2(do_wmemb, ptrint, u8);

bool do_wmemw::cmd(ptrint addr, u16 value, std::ostream& outstream)
{
	if (!IO::Instance().WriteMem(addr, 2, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA2(do_wmemw, ptrint, u16);

bool do_wmeml::cmd(ptrint addr, u32 value, std::ostream& outstream)
{
	if (!IO::Instance().WriteMem(addr, 4, &value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA2(do_wmeml, ptrint, u32);
