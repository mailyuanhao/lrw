#include "cmd_ioport.h"
#include "io/io.h"

bool do_inb::cmd(u16 portAddr, std::ostream& outstream)
{
	outstream<<IO::Instance().io_inb_p(portAddr);	
	return true;
}

INSERT_CMD_PARA1(do_inb, u16);

bool do_inw::cmd(u16 portAddr, std::ostream& outstream)
{
	outstream<<IO::Instance().io_inw_p(portAddr);
	return true;
}

INSERT_CMD_PARA1(do_inw, u16);

bool do_inl::cmd(u16 portAddr, std::ostream& outstream)
{
	outstream<<IO::Instance().io_inl_p(portAddr);
	return true;
}

INSERT_CMD_PARA1(do_inl, u16);

bool do_outb::cmd(u16 portAddr, u8 value, std::ostream& outstream)
{
	IO::Instance().io_outb_p(value, portAddr);
	return true;
}

INSERT_CMD_PARA2(do_outb, u16, u8);

bool do_outw::cmd(u16 portAddr, u16 value, std::ostream& outstream)
{
	IO::Instance().io_outw_p(value, portAddr);
	return true;
}

INSERT_CMD_PARA2(do_outw, u16, u16);

bool do_outl::cmd(u16 portAddr, u32 value, std::ostream& outstream)
{
	IO::Instance().io_outl_p(value, portAddr);
	return true;
}

INSERT_CMD_PARA2(do_outl, u16, u32);

