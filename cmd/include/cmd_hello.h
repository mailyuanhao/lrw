#ifndef _CMD_HELLO_H_
#define _CMD_HELLO_H_

//必須加載的頭文件
#include "cmdimp.h"

//每個命令以一個類的形勢體現
//該類必須繼承至do_operate,do_read或者do_write之一.
class do_hello :
	public do_operate
{
public:
	//命令實現主函數,必須實現
	//該函數完成命令操作,并把結果/錯誤/狀態信息通過
	//outstream輸出
	//參數列表:最后的std::ostream& outstream是必選參數
	//在該參數前面可以添加任意數量任意類型的參數.
	//該hello命令使用了兩個參數string smth和u32 count
	//注意目前只支持0-5個參數,而且參數類型必須是內置類型或者重載了
	//輸入輸出操作符的自定義類型
	bool cmd(string smth, u32 count, std::ostream& outstream);

	//命令名稱,必須實現
	//返回該命令在命令行上調用的名稱,如I32,RPCI
	//不支持命令重載,不允許出現相同name的命令.
	const string& CMDName() const
	{
		static string name_("HELLO");
		return name_;
	}

	//命令描述,必須實現
	//描述具體命令,如Input port32,Read PCI byte
	const string& CMDDescript() const
	{
		static string desc_("HELLO SOMETHING");
		return desc_;
	}

	//命令幫助信息,必須實現
	//提供命令的詳細幫助信息;
	ostream& Help(ostream& outstream) const
	{
		outstream<<"HELLO <smth> <count>			HELLO SMTH count times";
		return outstream;
	}
};


#endif //_CMD_HELLO_H_
