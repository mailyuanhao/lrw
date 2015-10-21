#ifndef _SINGLE_H_
#define _SINGLE_H_

//Client class 需要自己保證構造，拷貝構造為私有的
//而且要聲明SingletonHolder<T>為友元
//class A
//{
//friend class SingletonHolder<A>;
//pbulic:
//	print()
//	{
//		...
//	}
//private:
//	A(){};
//	A(const A&){..};
//};
//
//typedef SingletonHolder<A> SingleA;
//SingleA::Instance().print()
//

template <class T>
class SingletonHolder
{
public:
	static T& Instance()
	{
		static T instance_;
		return instance_;
	}
private:
	//protection
	SingletonHolder();
};

#endif //_SINGLE_H_
