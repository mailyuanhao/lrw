#include "cmd_pci.h"
#include "io/io.h"

bool do_rpcib::cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().Rpci(bus, dev, func, offset, BYTE_S, value))
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
INSERT_CMD_PARA4(do_rpcib, u8, u8, u8, u8);

bool do_rpciw::cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().Rpci(bus, dev, func, offset, WORD_S, value))
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
INSERT_CMD_PARA4(do_rpciw, u8, u8, u8, u8);

bool do_rpcil::cmd(u8 bus, u8 dev, u8 func, u8 offset, std::ostream& outstream)
{
	u32 value = 0;
	if (!IO::Instance().Rpci(bus, dev, func, offset, DWORD_S, value))
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
INSERT_CMD_PARA4(do_rpcil, u8, u8, u8, u8);

bool do_wpcib::cmd(u8 bus, u8 dev, u8 func, u8 offset, u8 value, std::ostream& outstream)
{
	if (!IO::Instance().Wpci(bus, dev, func, offset, BYTE_S, value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA5(do_wpcib, u8, u8, u8, u8, u8);

bool do_wpciw::cmd(u8 bus, u8 dev, u8 func, u8 offset, u16 value, std::ostream& outstream)
{
	if (!IO::Instance().Wpci(bus, dev, func, offset, WORD_S, value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA5(do_wpciw, u8, u8, u8, u8, u16);

bool do_wpcil::cmd(u8 bus, u8 dev, u8 func, u8 offset, u32 value, std::ostream& outstream)
{
	if (!IO::Instance().Wpci(bus, dev, func, offset, DWORD_S, value))
	{
		const ErrorLog& err = IO::Instance().getError();
		for (ErrorLog::const_iterator it = err.begin(); it != err.end(); ++it)
		{
			outstream<<*it<<std::endl;
		}
	}

	return true;
}
INSERT_CMD_PARA5(do_wpcil, u8, u8, u8, u8, u32);
