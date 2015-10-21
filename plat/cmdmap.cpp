#include "cmdmap.h"
#include "command.h"

//這個函數需要command的定義,故抽到cpp中,而不放在頭文件中
void CMDMap::insertCMD(pCMD pd)
{
	m_map.insert(mapOfCMD::value_type(pd->CMDName(), pd));
}

pCMD CMDMap::getCMD(const string& cmd)
{
	pCMD temp = NULL;
	if (isValid())
	{
		mapOfCMD::iterator it = m_map.find(cmd);

		if (it != m_map.end())
		{
			temp = (*it).second;
		}
	}

	return temp;
}

