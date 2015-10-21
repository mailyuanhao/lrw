#ifndef _DATATYPE_H_
#define _DATATYPE_H_

//�����]unicode����r
#include <string>
using std::string;

#include <list>
typedef std::list<string> ErrorLog;

#include <ostream>
using std::ostream;
using std::istream;

#include <sstream>
typedef std::ostringstream ostr;
typedef std::istringstream istr;

#include <set>
#include <map>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long ptrint;

//typedef unsigned char u8;
//�]�k����..���ʹ��unsigned char ��ݔ���ĕr��������}.ݔ��ASCII�a...
//ֻ���˶��������,ϣ������������....
class u8
{
	friend ostream& operator<<(ostream& ostr, const u8& u);
	friend istream& operator>>(istream& instr, u8& u);
public:
	u8(unsigned char v = 0):m_u(v){}
	//�D�Q������,�����m_u���������.���^Ҳ�Ǜ]���k��������.
	//����D�Q��unsigned char�t����ɟo��������Ҫ���õĲ���,��a += 8;
	operator unsigned char&()
	{
		return m_u;
	}
private:
	unsigned char m_u;
};

typedef int s32;
typedef short s16;
//typedef signed char s8;
//typedef short s8;



#endif //_DATATYPE_H_
