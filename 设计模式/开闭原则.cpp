#include<iostream>
using namespace std;

#if 0

//计算
class Caculator
{
public:
	Caculator(int a, int b, string oper)
	{
		this->m_a = a;
		this->m_b = b;
		this->m_operator = oper;
	}
	
	int getResult()
	{
		if(m_operator.compare("+") == 0)
		{
			return m_a + m_b;
		}
		else if(m_operator.compare("-") == 0)
		{
			return m_a - m_b;
		}

	}
private:
	int m_a;
	int m_b;
	string m_operator;
};

void test01()
{
	Caculator* caculator = new Caculator(10,20,"+");
	cout<<caculator->getResult()<<endl;
}


//如果增加新功能就需要修改getRsult方法，有报错的可能，而增加新功能应该保证不影响其他已经完成的功能
#endif


//抽象类
class AbstractCaculator
{
public:
	virtual int getResult() = 0;
	virtual void setNum(int, int)= 0;
};

//加法
class Plus :public AbstractCaculator
{
public:
	virtual void setNum(int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	virtual int getResult()
	{
		return m_a+m_b;
	}
private:
	int m_a;
	int m_b;

};
//减法
class Minus :public AbstractCaculator
{
public:
	virtual void setNum(int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	virtual int getResult()
	{
		return m_a-m_b;
	}
private:
	int m_a;
	int m_b;

};
//加新功能，源代码安全

void test02()
{
	AbstractCaculator* caculator = new Plus;
	caculator->setNum(10,20);
	cout<<caculator->getResult()<<endl;
	delete caculator;
	//AbstractCaculator* caculator = new Minus;


}
int main02()
{
	test02();
	return 0;
}