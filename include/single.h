#ifndef _SINGLE_H_
#define _SINGLE_H_

//Client class ��Ҫ�Լ����C���죬��ؐ�����˽�е�
//����Ҫ��SingletonHolder<T>����Ԫ
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
