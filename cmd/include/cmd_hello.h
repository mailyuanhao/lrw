#ifndef _CMD_HELLO_H_
#define _CMD_HELLO_H_

//��횼��d���^�ļ�
#include "cmdimp.h"

//ÿ��������һ����΄��w�F
//ԓ���^����do_operate,do_read����do_write֮һ.
class do_hello :
	public do_operate
{
public:
	//����F������,��회��F
	//ԓ��������������,���ѽY��/�e�`/��B��Ϣͨ�^
	//outstreamݔ��
	//�����б�:����std::ostream& outstream�Ǳ��x����
	//��ԓ����ǰ�����������┵��������͵ą���.
	//ԓhello����ʹ���˃ɂ�����string smth��u32 count
	//ע��Ŀǰֻ֧��0-5������,���҅�����ͱ���ǃ�����ͻ������d��
	//ݔ��ݔ�����������Զ��x���
	bool cmd(string smth, u32 count, std::ostream& outstream);

	//�������Q,��회��F
	//����ԓ���������������{�õ����Q,��I32,RPCI
	//��֧���������d,�����S���F��ͬname������.
	const string& CMDName() const
	{
		static string name_("HELLO");
		return name_;
	}

	//��������,��회��F
	//�������w����,��Input port32,Read PCI byte
	const string& CMDDescript() const
	{
		static string desc_("HELLO SOMETHING");
		return desc_;
	}

	//���������Ϣ,��회��F
	//�ṩ�����Ԕ��������Ϣ;
	ostream& Help(ostream& outstream) const
	{
		outstream<<"HELLO <smth> <count>			HELLO SMTH count times";
		return outstream;
	}
};


#endif //_CMD_HELLO_H_
