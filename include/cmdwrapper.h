#ifndef _CMDWRAPPER_H_
#define _CMDWRAPPER_H_

#include "single.h"
#include "datatype.h"
#include "util.h"
#include "command.h"
#include "cmdmap.h"

//僅僅爲了減少一些代碼量,沒別的用途
template <class Worker>
class ParamBase:
	public command
{
protected:
	virtual const string& GetCMDName() const;
	virtual u32 GetCMDproperty() const;
	virtual ostream& DoHelp(ostream& outstream) const;
	virtual const string& GetCMDDescript() const;

protected:
	Worker m_worker;
};

template <class Worker>
u32 ParamBase<Worker>::GetCMDproperty() const
{
	return m_worker.CMDproperty();
}

template <class Worker>
const string& ParamBase<Worker>::GetCMDName() const
{
	return m_worker.CMDName();
}

template <class Worker>
ostream& ParamBase<Worker>::DoHelp(ostream& outstream) const
{
	return m_worker.Help(outstream);
}

template <class Worker>
const string& ParamBase<Worker>::GetCMDDescript() const
{
	return m_worker.CMDDescript();
}

//不需要參數的命令可以使用這個模板
template <class Worker>
class Param0 :
	public ParamBase<Worker>
{
friend class SingletonHolder<Param0<Worker> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param0(){}
	Param0(const Param0<Worker>&);
	Param0<Worker>& operator = (const Param0<Worker>&);
};

template <class Worker>
bool Param0<Worker>::DoCMD(const std::string &para, std::ostream &outstream)
{
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(outstream))
	{
		return false;
	}
	return true;
}



//所有含有1個參數的命令的wrapper類,注意讀取函數的返回值不算在參數個數内;
template <class Worker, typename type1>
class Param1 :
	public ParamBase<Worker>
{
	friend class SingletonHolder<Param1<Worker, type1> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param1(){}
	Param1(const Param1<Worker, type1>&);
	Param1<Worker, type1>& operator = (const Param1<Worker, type1>&);
};

template <class Worker, typename type1>
bool Param1<Worker, type1>::DoCMD(const std::string &para, std::ostream &outstream)
{
	type1 p1;
	if (!parsePara(para, p1))
	{
		outstream<<CMD_LINE_ERROR;
		return false;
	}

	//輸出經過解析后的命令行.
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<" "<<p1<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(p1, outstream))
	{
		return false;
	}
	return true;
}

//兩個參數的wrapper
template <class Worker, typename type1, typename type2>
class Param2 :
	public ParamBase<Worker>
{
	friend class SingletonHolder<Param2<Worker, type1, type2> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param2(){}
	Param2(const Param2<Worker, type1, type2>&);
	Param2<Worker, type1, type2>& operator = (const Param2<Worker, type1, type2>&);
};

template <class Worker, typename type1, typename type2>
bool Param2<Worker, type1, type2>::DoCMD(const std::string &para, 
										 std::ostream &outstream)
{
	type1 p1;
	type2 p2;
	if (!parsePara(para, p1, p2))
	{
		outstream<<CMD_LINE_ERROR;
		return false;
	}

	//輸出經過解析后的命令行.
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<" "<<p1<<" "<<p2<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(p1, p2, outstream))
	{
		return false;
	}
	return true;
}


//三個參數的wrapper
template <class Worker, typename type1, typename type2, typename type3>
class Param3 :
	public ParamBase<Worker>
{
	friend class SingletonHolder<Param3<Worker, type1, type2, type3> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param3(){}
	Param3(const Param3<Worker, type1, type2, type3>&);
	Param3<Worker, type1, type2, type3>& operator = 
		(const Param3<Worker, type1, type2, type3>&);
};

template <class Worker, typename type1, typename type2, typename type3>
bool Param3<Worker, type1, type2, type3>::DoCMD(const std::string &para, 
												std::ostream &outstream)
{
	type1 p1;
	type2 p2;
	type3 p3;
	if (!parsePara(para, p1, p2, p3))
	{
		outstream<<CMD_LINE_ERROR;
		return false;
	}

	//輸出經過解析后的命令行.
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<" "<<p1<<" "<<p2<<" "<<p3<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(p1, p2, p3, outstream))
	{
		return false;
	}
	return true;
}

//四個參數的wrapper
template <class Worker, typename type1, typename type2, typename type3, typename type4>
class Param4 :
	public ParamBase<Worker>
{
	friend class SingletonHolder<Param4<Worker, type1, type2, type3, type4> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param4(){}
	Param4(const Param4<Worker, type1, type2, type3, type4>&);
	Param4<Worker, type1, type2, type3, type4>& operator = 
		(const Param4<Worker, type1, type2, type3, type4>&);
};

template <class Worker, typename type1, typename type2, typename type3, typename type4>
bool Param4<Worker, type1, type2, type3, type4>::DoCMD(const std::string &para, 
											   std::ostream &outstream)
{
	type1 p1;
	type2 p2;
	type3 p3;
	type4 p4;
	if (!parsePara(para, p1, p2, p3, p4))
	{
		outstream<<CMD_LINE_ERROR;
		return false;
	}

	//輸出經過解析后的命令行.
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(p1, p2, p3, p4, outstream))
	{
		return false;
	}
	return true;
}

//五個參數的wrapper
template <class Worker, typename type1, typename type2, typename type3, typename type4, typename type5>
class Param5 :
	public ParamBase<Worker>
{
	friend class SingletonHolder<Param5<Worker, type1, type2, type3, type4, type5> >;
protected:
	virtual bool DoCMD(const string& para, ostream& outstream);
private:
	Param5(){}
	Param5(const Param5<Worker, type1, type2, type3, type4, type5>&);
	Param5<Worker, type1, type2, type3, type4, type5>& operator = 
		(const Param5<Worker, type1, type2, type3, type4, type5>&);
};

template <class Worker, typename type1, typename type2, typename type3, typename type4, typename type5>
bool Param5<Worker, type1, type2, type3, type4, type5>::DoCMD(const std::string &para, 
													   std::ostream &outstream)
{
	type1 p1;
	type2 p2;
	type3 p3;
	type4 p4;
	type5 p5;
	if (!parsePara(para, p1, p2, p3, p4, p5))
	{
		outstream<<CMD_LINE_ERROR;
		return false;
	}

	//輸出經過解析后的命令行.
	outstream<<ParamBase<Worker>::m_worker.CMDDescript()<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<"\n";

	if (!ParamBase<Worker>::m_worker.cmd(p1, p2, p3, p4, p5, outstream))
	{
		return false;
	}
	return true;
}


#endif //_CMDWRAPPER_H_
