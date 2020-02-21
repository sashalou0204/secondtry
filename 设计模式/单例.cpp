#include <iostream>
using namespace std;

class A
{
private:
	A()
	{
		a = new A;//就，新对象了
	}
public:
	static A* getInstance()
	{
		return a;//对外接口，使得对象可获得
	}
private:
	static A* a; 
};


A* A::a = NULL;

	//实现单例的步骤：
	//1.构造函数私有化
	//2. 增加静态的且私有的当前类的指针变量
	//3. 提供一个静态的对外接口，可以让用户获得单例对象




//单例又分为： 懒汉式，饿汉式

//懒
class SingleCase_lazy
{
private:
	SingleCase_lazy(){}//在构造函数中是没有初始化的
	//外部接口函数
public:
	static SingleCase_lazy* getInstance()
	{
		if(pSingleCase == NULL)
		{
			//第一次调用之后才会创建
			pSingleCase = new SingleCase_lazy;
		}
		return pSingleCase;
	}
private:
	static SingleCase_lazy* pSingleCase;

};
//类外初始化
SingleCase_lazy*SingleCase_lazy::pSingleCase = NULL;


//饿
class SingleCase_hungry
{
private:
	SingleCase_hungry(){cout<<"这是饿汉式的构造函数"<<endl;}
public:
	static SingleCase_hungry* getInstance()
	{
		return pSingleCase;
	

	/*
	static void freeSpace()
	{
		if(pSingleCase != NULL)
		{
			delete pSingleCase;
		}*/
		//危险,因为只有一个对象，一删就没了
//其实没必要考虑释放内存的问题
	}
			
private:
	static SingleCase_hungry* pSingleCase;

};
SingleCase_hungry* SingleCase_hungry::pSingleCase = new SingleCase_hungry;//在main函数调用前就创建好了


//线程安全问题，懒汉式线程不安全；饿汉式ok

void test01()
{
	SingleCase_lazy* p1 = SingleCase_lazy::getInstance();
	SingleCase_lazy* p2 = SingleCase_lazy::getInstance();
	if(p1 == p2)
	{
		cout<<"两个指针指向同一块内存空间，是单例"<<endl;
	}
	else
	{
		cout<<"不是单例模式"<<endl;
	}

	SingleCase_hungry* p3 = SingleCase_hungry::getInstance();
	SingleCase_hungry* p4 = SingleCase_hungry::getInstance();
	if(p3 == p4)
	{
		cout<<"两个指针指向同一块内存空间，是单例"<<endl;
	}
	else
	{
		cout<<"不是单例模式"<<endl;
	}

}

/*
void test02()
{
	SingleCase_hungry::freeSpace();//释放
}*/

int main01(void)
{
	//cout<<"开始调用main函数"<<endl;
	//A::getInstance();
	test01(); //ok


	return 0;
}
