#include "cmdmap.h"
#include "cmd_help.h"

bool do_help::cmd(string para, std::ostream& outstream)
{
	istr inputStr(para);
	string cmdName;
	string cmdPara;
	inputStr>>cmdName;
	inputStr>>cmdPara;

	if (inputStr)
	{
		//有參數的help,參數為cmdPara
		pCMD pcmd = gCMD::Instance().getCMD(cmdPara);
		if (NULL == pcmd)
		{
			outstream<<"Unknown CMD name, input again";
		}else
		{
			outstream<<"Help Information of  "<<cmdPara<<":"<<std::endl;
			pcmd->Help(outstream);
		}
	}else
	{
		//無參數的help;,遍歷命令.
		const CMDMap::mapOfCMD mc = gCMD::Instance().getMap();
		CMDMap::mapOfCMD::const_iterator cit = mc.begin();
		outstream<<"CMD Name List:";
		outstream<<"\n\tCMD Name\tCMD Descript";
		while (cit != mc.end())
		{
			outstream<<std::endl;
			outstream<<"\t"<<(*cit).second->CMDName()<<"\t\t"<<(*cit).second->CMDDescript();
			++cit;
		}
		outstream<<"\n\n\tInput help xx for detial information .Test help help\n";
	}
	return true;
}

//插入這個功能
INSERT_CMD(para_str_help, do_help);
