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
		//�Ѕ�����help,������cmdPara
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
		//�o������help;,��v����.
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

//�����@������
INSERT_CMD(para_str_help, do_help);
