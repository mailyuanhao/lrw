#ifndef _CMDMAP_H_
#define _CMDMAP_H_

#include <algorithm>
#include "datatype.h"
#include "single.h"
#include "command.h"

class stringCmpNoCase
{
public:
	bool operator() (const string& s1, const string& s2) const
	{
		return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
	}
private:
	static bool nocase_compare(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
};

typedef command* pCMD;

//���ڱ������е�command�ӌ����ָ�
//�ڽ��յ������,����ԓMap�в���.
class CMDMap
{
	friend class SingletonHolder<CMDMap>;
	//���˷���help��v����,�o�����ؙ�.
	friend class do_help;

public:
	void insertCMD(pCMD pd);

	pCMD getCMD(const string& cmd);


private:
	CMDMap()
	{
		stateFlag(exist);
	}

	~CMDMap()
	{
		stateFlag(destroyed);
	}

private:
	typedef std::map<string, pCMD, stringCmpNoCase> mapOfCMD;
	mapOfCMD m_map;

	enum State
	{
		doNotChange =0,
		notCreated,
		exist,
		destroyed
	};

	static State stateFlag( State newState = doNotChange )
	{
		static State state = notCreated;
		if ( newState != doNotChange )
		{
			state = newState;
		}
		return state;
	}

	static bool isValid()
	{
		return stateFlag() != destroyed;
	}

	//�@�������H��helpʹ��,�����Ҫ��v���е�cmd,
	const mapOfCMD& getMap()
	{
		return m_map;
	}

};

typedef SingletonHolder<CMDMap> gCMD;

template<class T, template <class>class Holder = SingletonHolder>
class AutoRegister
{
public:
	AutoRegister()
	{
		gCMD::Instance().insertCMD(&(Holder<T>::Instance()));
	}
};

#endif //_CMDMAP_H_
