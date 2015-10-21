#ifndef _HELP_CMD_H_
#define _HELP_CMD_H_
#include "cmdwrapper.h"
#include "cmdimp.h"

//help 函數太過特殊了,他接收0或者1個string參數,所以定義一個新的Param宏.
//哎,還是考慮不周到,麻煩死了.....

template <class Worker>
class para_str_help :
	public ParamBase<Worker>
{
	friend class SingletonHolder<para_str_help<Worker> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	para_str_help(){}
	para_str_help(const para_str_help<Worker>&);
	para_str_help<Worker>& operator = (const para_str_help<Worker>&);
};

template <class Worker>
bool para_str_help<Worker>::DoCMD(const std::string &para, std::ostream &outstream)
{
	if (!ParamBase<Worker>::m_worker.cmd(para, outstream))
	{
		return false;
	}
	return true;
}

class do_help :
	public do_operate
{
public:
	bool cmd(string para, std::ostream& outstream);

	const string& CMDName() const
	{
		static string name_("help");
		return name_;
	}

	const string& CMDDescript() const
	{
		static string desc_("Print Help");
		return desc_;
	}

	ostream& Help(ostream& outstream) const
	{
		outstream<<"\"help\" will list all the cmd registered\n"
			<<"\"help xx\" will print the xx's help information";
		return outstream;
	}
};

#endif //_HELP_CMD_H_
