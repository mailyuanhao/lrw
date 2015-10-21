#include "cmd_hello.h"

//具體實現函數.該命令僅僅是輸出count遍hello smth;
bool do_hello::cmd(string smth, u32 count, std::ostream& outstream)
{
	for (u32 i = 0; i < count ; i++)
	{
		outstream<<"hello "<<smth<<std::endl;
	}
	return true;
}

//插入該命令,必須進行該操作,否則,該命令將不能被調用
//用了兩個可選參數,故使用INSERT_CMD_PARA2,
//util.h定義有其余的插入宏
//第一個參數為命令類的名稱,后面依次跟cmd函數的可選參數類型;
//類型必須依次對應.
INSERT_CMD_PARA2(do_hello, string, u32);

