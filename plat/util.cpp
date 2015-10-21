#include "util.h"
ostream& operator<<(ostream& ostr, const u8& u)
{
	ostr<<(int)u.m_u;
	return ostr;
}

istream& operator>>(istream& instr, u8& u)
{
	u16 temp;
	instr>>temp;
	if (temp > (unsigned char)(~0))
	{
		//���������u8�ķ���,�t�O��fail!!
		instr.setstate(std::ios_base::failbit);
	}else
	{
		u.m_u = static_cast<unsigned char>(temp);
	}
	return instr;
}
