#ifndef _CMDIMP_H_
#define _CMDIMP_H_
#include "cmdwrapper.h"

//該基類沒任何用處，至少現在我還沒發現。
//添加它, 僅僅是爲了讓那些do_xx類能有個共同的父親。
//父親沒用，至少它們有了兄弟關係，不會感到孤單了。呵呵。
class do_base
{
};

//呵呵,有個共同的父親還是不錯的,又可以減少一部分代碼量
//繼承都被我用來干這個了...罪過啊
class do_read :
	public do_base
{
public:
	const u32 CMDproperty() const
	{
		return READ_P;
	}
};

class do_write :
	public do_base
{
public:
	const u32 CMDproperty() const
	{
		return WRITE_P;
	}
};

class do_operate :
	public do_base
{
public:
	const u32 CMDproperty() const
	{
		return OPERATE_P;
	}
};

#endif //_CMDIMP_H_
