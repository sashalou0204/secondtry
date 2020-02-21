#include<iostream>
using namespace std;

class AbstractCar
{
public:
	virtual void run() = 0;
};

class car1 : public AbstractCar
{
public:
	virtual void run()
	{
		cout<<"car1 run..."<<endl;
	}
private:

};


class car2 : public AbstractCar
{
public:
	virtual void run()
	{
		cout<<"car2 run..."<<endl;
	}
private:

};

//每一种具体情况都要重新写类，
#if 0
class person : public car2
{
public:
	void DF()
	{run();}
};
class personB:public car1
{};
#endif




//使用组合

class Person
{
public:
	void setCar(AbstractCar* car)
	{
		this->car = car;
	}
	void DF()
	{
		this->car->run();
	}
	~Person()
	{
		if(this->car!= NULL)
		{
			delete this->car;
		}
	}
public:
	AbstractCar* car;//一个抽象的汽车类
};
void test04()
{
	Person* p = new Person;
	p->setCar(new car1);
	p->DF();
	//delete 再set ok
}


int main04()
{
	test04();
	return 0;
}