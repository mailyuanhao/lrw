#include <iostream>
#include <string.h>
#include "datatype.h"
#include "io/io.h"
#include "util.h"
#include "cmdmap.h"

#define COUT	std::cout
#define CIN		std::cin

#define QUIT "quit"

void trimCMDLine(string& cmdline)
{
	string fileter(" \t");
	string::size_type itb = cmdline.find_first_not_of(fileter);
	string::size_type ite = cmdline.find_last_not_of(fileter);
	if (itb != ite || itb < cmdline.size())
	{
		cmdline.assign(cmdline, itb, ite - itb + 1);
	}else
	{
		cmdline.clear();	
	}
}

void DoCMD(const string& cmdLine, pCMD pcmd)
{
	bool bRet = false;
	bRet = pcmd->CMD(cmdLine, COUT);
	if (!bRet)
	{
		//...
	}
}

void DealWithCMDLine(string cmdline)
{
	trimCMDLine(cmdline);
	if (!cmdline.empty())
	{
		istr instr(cmdline);
		string cmdName;
		instr>>cmdName;
		if (instr)
		{
			pCMD pcmd = gCMD::Instance().getCMD(cmdName);

			if (pcmd != NULL)
			{
				DoCMD(cmdline, pcmd);
				return;
			}
		}
	}

	COUT<<BAD_CMD<<"\n";
}

void loop(void)
{
	COUT<<FIRST_HELP_INFO<<std::endl;
	do 
	{
		COUT<<PRE_FIX;
		string cmdline;
		getline(CIN, cmdline);


		//bye bye
		if (cmdline == string(QUIT))
		{
			break;
		}

		DealWithCMDLine(cmdline);
		COUT<<std::endl;
	} while(true);
}
bool CheckPlat()
{
	/*-
	 * size of base data
	 */
	if (sizeof(u8) != 1
	|| sizeof(u16) != 2
	|| sizeof(u32) != 4
	   )
	{
		return false;
	}
	/*
	 * little endion
	 */
	u32 temp = 1;
	if ((u8)temp != 1
	|| (u16)temp != 1
	)
	{
		return false;
	}
	return true;
}
/*
 *	Add anoter way to use this tool.
 *	user can easily type the cmd line like: lrw rpci xx xx xx xx
 *	to execute the rpci cmd. In this mode lrw will return at once
 *	,after the rpci cmd is finished,without entering the shell mode.
 *	By this way user can use the comfortable traits provided by 
 *	the shell. Use up arrow or down arrow to get the historical cmd 
 *	which had been typed, for example.
 *
 */
#ifndef UNIT_TEST
int main(int argc, char** argv)
{
	if (!CheckPlat())
	{
		COUT<<"This platform is not supported"<<std::endl;
		return 1;
	}
	COUT<<std::showbase<<std::hex;
	//driver ³õÊ¼»¯
	if (IO::Instance().init())
	{	
		if (argc == 1 || strcasecmp(argv[1], SHELL_MODE) == 0)
		{
			//all right, user wanted the shell mode~
			COUT<<std::showbase<<std::hex;
			loop();
		}
		else if (strcasecmp(argv[1], HELP_STR) == 0)
		{
			COUT<<"\tType lrw or lrw "<<SHELL_MODE<<" to enter shell mode\n"
			<<"\tType lrw cmd xx xx xx to directly execute the expect cmd you want\n"
			<<"\tType lrw help to get more info of all the commands\n";
		}
		else
		{
			string cmd_line;
			for (int i = 1; i < argc; ++i)
			{
				cmd_line += argv[i];
				cmd_line += " ";
			}
			DealWithCMDLine(cmd_line);
		}

	}else
	{
		COUT<<DRIVER_INIT_ERROR<<std::endl;
	}

	return 0;
}
#endif
