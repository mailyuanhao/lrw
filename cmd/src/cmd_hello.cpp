#include "cmd_hello.h"

//���w���F����.ԓ����H�H��ݔ��count��hello smth;
bool do_hello::cmd(string smth, u32 count, std::ostream& outstream)
{
	for (u32 i = 0; i < count ; i++)
	{
		outstream<<"hello "<<smth<<std::endl;
	}
	return true;
}

//����ԓ����,����M��ԓ����,��t,ԓ������ܱ��{��
//���˃ɂ����x����,��ʹ��INSERT_CMD_PARA2,
//util.h���x������Ĳ����
//��һ����������������Q,�������θ�cmd�����Ŀ��x�������;
//��ͱ�����Ό���.
INSERT_CMD_PARA2(do_hello, string, u32);

