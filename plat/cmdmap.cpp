#include "cmdmap.h"
#include "command.h"

//�@��������Ҫcommand�Ķ��x,�ʳ鵽cpp��,���������^�ļ���
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

