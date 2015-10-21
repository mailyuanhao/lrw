#ifndef _DATATYPE_H_
#define _DATATYPE_H_

//不考慮unicode的情況
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
//沒辦法了..如果使用unsigned char 在輸出的時候會出問題.輸出ASCII碼...
//只好退而求其次了,希望能正常工作....
class u8
{
	friend ostream& operator<<(ostream& ostr, const u8& u);
	friend istream& operator>>(istream& instr, u8& u);
public:
	u8(unsigned char v = 0):m_u(v){}
	//轉換成引用,會造成m_u被任意更改.不過也是沒有辦法的事情.
	//如果轉換成unsigned char則會造成無法執行需要引用的操作,如a += 8;
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
