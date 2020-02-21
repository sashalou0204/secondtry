#include<iostream>
#include<string>
#include<vector>
using namespace std;


class AbstractBuilding
{
public:
	virtual void sale() = 0;
	string m_Quality;
};


//A楼
class BuildingA : public AbstractBuilding
{
public:
	BuildingA ()
	{
		m_Quality = "好";
	}
	virtual void sale()
	{
		cout<<"楼A"<< m_Quality<<" ， 买了"<<endl;
	}
};

//B楼
class BuildingB : public AbstractBuilding
{
public:
	BuildingB()
	{
		m_Quality = "一般";
	}
	virtual void sale()
	{
		cout<<"楼B"<<m_Quality<<" ， 买了"<<endl;
	}

};
#if 0
//用户想选一个一般的
void test01()
{
	BuildingA* ba = new BuildingA;
	if(ba->m_Quality == "一般")
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if(bb->m_Quality == "一般")
	{
		bb->sale();
	}
}
//每个类（楼）都要去调用，耦合性太强
#endif


//考虑中间类 让中介去管理所有的楼， 用户直接与中介打交道，中介给用户所需要的信息
class Mediator
{
public:
	Mediator()
	{
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}

	//对外提供一个接口,让用户去找
	AbstractBuilding* findBuilding(string quality)
	{
		for(vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end();it++)
		{
			if((*it)->m_Quality == quality)
			{
				return *it;
			}
			else return NULL;

		}

	}


	~Mediator()
	{
		for(vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end();it++)
		{
			if(*it != NULL)
			{
				delete *it;
			}
		}
	}
private:
	vector<AbstractBuilding*> vBuilding;//管理楼

};

void test03()
{
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findBuilding("一般");//让中介去找到想要的一般的楼
	if(building != NULL)
	{
		building->sale();
	}
	else
		cout<<"没有符合该条件的楼"<<endl;

}

//不需要和具体类打交道了

int main03()
{
	//test01();
	test03();//ok
	return 0;
}