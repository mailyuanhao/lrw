#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "datatype.h"

class command
{
public:
	bool CMD(const string& para, ostream& outstream)
	{
		return this->DoCMD(para, outstream);
	}

	const string& CMDName() const
	{
		return this->GetCMDName();
	}

	u32 CMDproperty() const
	{
		return this->GetCMDproperty();
	}

	ostream& Help(ostream& outstream) const
	{
		return this->DoHelp(outstream);
	}

	const string& CMDDescript() const
	{
		return this->GetCMDDescript();
	}

	virtual ~command() = 0;

protected:
	virtual bool DoCMD(const string& para, ostream& outstream) = 0;
	virtual const string& GetCMDName() const = 0;
	virtual u32 GetCMDproperty() const = 0;
	virtual ostream& DoHelp(ostream& outstream) const = 0;
	virtual const string& GetCMDDescript() const = 0;
};

#endif //_COMMAND_H_
