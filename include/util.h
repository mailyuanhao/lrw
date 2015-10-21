#ifndef _UTIL_H_
#define _UTIL_H_
#include "datatype.h"

//已知問題
//1:字符串最后的空格不會被自動忽略,比如str = "ttt, 11, 22 "
//	如果調用parsePara(ttt, a, b)會false,因為最后有個空格
//	在調用eof()時該函數會返回false;
//	沒想到比較簡單的解決方法,而且影響不大,暫時不修改了
//	OK  在main函數進行trim保證傳進來的都是整理過的.

//	可能問題點,出現過一次傳入正確的參數但是不能正常eof的現象
//	后來就沒在發生,希望不是...有內存bug,.....


template <typename type1>
bool doparsePara(istr& instr, type1& para)
{
	string CMDName;

	instr>>CMDName;
	if (instr)
	{
		instr>>para;
		if (instr)
		{
			return true;
		}
	}
	return false;
}

template <typename type1, typename type2>
bool doparsePara(istr& instr, type1& para, type2& para2)
{
	if (doparsePara(instr, para))
	{
		instr>>para2;
		if (instr)
		{
			return true;
		}
	}
	return false;
}

template <typename type1, typename type2, typename type3>
bool doparsePara(istr& instr, type1& para, type2& para2, type3& para3)
{
	if (doparsePara(instr, para, para2))
	{
		instr>>para3;
		if (instr)
		{
			return true;
		}
	}
	return false;
}

template <typename type1, typename type2, typename type3, typename type4>
bool doparsePara(istr& instr, type1& para, type2& para2, type3& para3, type4& para4)
{
	if (doparsePara(instr, para, para2, para3))
	{
		instr>>para4;
		if (instr)
		{
			return true;
		}
	}
	return false;
}

template <typename type1, typename type2, typename type3, typename type4, typename type5>
bool doparsePara(istr& instr, type1& para, type2& para2, type3& para3, type4& para4, type5& para5)
{
	if (doparsePara(instr, para, para2, para3, para4))
	{
		instr>>para5;
		if (instr)
		{
			return true;
		}
	}
	return false;
}

template <typename type1>
bool parsePara(string paraStr, type1& para)
{
	istr instr(paraStr);
	instr.unsetf(std::ios::dec);
	return doparsePara(instr, para) && instr.eof();
}

template <typename type1, typename type2>
bool parsePara(string paraStr, type1& para, type2& para2)
{
	istr instr(paraStr);
	instr.unsetf(std::ios::dec);
	return doparsePara(instr, para, para2) && instr.eof();
}

template <typename type1, typename type2, typename type3>
bool parsePara(string paraStr, type1& para, type2& para2, type3& para3)
{
	istr instr(paraStr);
	instr.unsetf(std::ios::dec);
	return doparsePara(instr, para, para2, para3) && instr.eof();
}

template <typename type1, typename type2, typename type3, typename type4>
bool parsePara(string paraStr, type1& para, type2& para2, type3& para3, type4& para4)
{
	istr instr(paraStr);
	instr.unsetf(std::ios::dec);
	return doparsePara(instr, para, para2, para3, para4) && instr.eof();
}

template <typename type1, typename type2, typename type3, typename type4, typename type5>
bool parsePara(string paraStr, type1& para, type2& para2, type3& para3, type4& para4, type5& para5)
{
	istr instr(paraStr);
	instr.unsetf(std::ios::dec);
	return doparsePara(instr, para, para2, para3, para4, para5) && instr.eof();
}


//some useful MACROS

//THESE 4 MACROS copied from CPPUNIT. 
#define JOIN( symbol1, symbol2 ) _DO_JOIN( symbol1, symbol2 )
#define _DO_JOIN( symbol1, symbol2 ) _DO_JOIN2( symbol1, symbol2 )
#define _DO_JOIN2( symbol1, symbol2 ) symbol1##symbol2
#define MAKE_UNIQUE_NAME( prefix ) JOIN( prefix, __LINE__ )

#define INSERT_CMD(para, cmdClass) \
	static AutoRegister< para < cmdClass > > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA0(cmdClass) \
	static AutoRegister< Param0 < cmdClass > > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA1(cmdClass, type1) \
	static AutoRegister< Param1 < cmdClass , type1> > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA2(cmdClass, type1, type2) \
	static AutoRegister< Param2 < cmdClass , type1, type2> > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA3(cmdClass, type1, type2, type3) \
	static AutoRegister< Param3 < cmdClass , type1, type2, type3> > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA4(cmdClass, type1, type2, type3, type4) \
	static AutoRegister< Param4 < cmdClass , type1, type2, type3, type4> > MAKE_UNIQUE_NAME(AutoRegister__)

#define INSERT_CMD_PARA5(cmdClass, type1, type2, type3, type4, type5) \
	static AutoRegister< Param5 < cmdClass , type1, type2, type3, type4, type5> > MAKE_UNIQUE_NAME(AutoRegister__)

//定義一些常量和宏


const char* const CMD_LINE_ERROR = "Can not parse your paras, check and \
input again\n";

const char* const FIRST_HELP_INFO = "Plz input your CMD, input: \"help\" for more\
 information and \"quit\" to exit";

const char* const DRIVER_INIT_ERROR = "Driver Init failed";

const char* const PRE_FIX = ">";

const char* const BAD_CMD = "Bad Command, \"help\" for help";

const char* const SHELL_MODE = "shell";
const char* const HELP_STR = "-h";

//命令的屬性,讀,寫,操作.
#define READ_P 0
#define WRITE_P 1
//暫時適用于0參數的命令,存在不???????
#define OPERATE_P 2



#endif //_UTIL_H_
