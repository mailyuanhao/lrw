#ifndef _CMDIMP_H_
#define _CMDIMP_H_
#include "cmdwrapper.h"

//ԓ��]�κ���̎�����٬F����߀�]�l�F��
//�����, �H�H�Ǡ���׌��Щdo_xx����Ђ���ͬ�ĸ��H��
//���H�]�ã��������������ֵ��P�S�������е����ˡ��Ǻǡ�
class do_base
{
};

//�Ǻ�,�Ђ���ͬ�ĸ��H߀�ǲ��e��,�ֿ��Ԝp��һ���ִ��a��
//�^�ж������Á���@����...���^��
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
