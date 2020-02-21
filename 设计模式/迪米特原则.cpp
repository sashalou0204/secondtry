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


//A¥
class BuildingA : public AbstractBuilding
{
public:
	BuildingA ()
	{
		m_Quality = "��";
	}
	virtual void sale()
	{
		cout<<"¥A"<< m_Quality<<" �� ����"<<endl;
	}
};

//B¥
class BuildingB : public AbstractBuilding
{
public:
	BuildingB()
	{
		m_Quality = "һ��";
	}
	virtual void sale()
	{
		cout<<"¥B"<<m_Quality<<" �� ����"<<endl;
	}

};
#if 0
//�û���ѡһ��һ���
void test01()
{
	BuildingA* ba = new BuildingA;
	if(ba->m_Quality == "һ��")
	{
		ba->sale();
	}
	BuildingB* bb = new BuildingB;
	if(bb->m_Quality == "һ��")
	{
		bb->sale();
	}
}
//ÿ���ࣨ¥����Ҫȥ���ã������̫ǿ
#endif


//�����м��� ���н�ȥ�������е�¥�� �û�ֱ�����н�򽻵����н���û�����Ҫ����Ϣ
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

	//�����ṩһ���ӿ�,���û�ȥ��
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
	vector<AbstractBuilding*> vBuilding;//����¥

};

void test03()
{
	Mediator* mediator = new Mediator;
	AbstractBuilding* building = mediator->findBuilding("һ��");//���н�ȥ�ҵ���Ҫ��һ���¥
	if(building != NULL)
	{
		building->sale();
	}
	else
		cout<<"û�з��ϸ�������¥"<<endl;

}

//����Ҫ�;�����򽻵���

int main03()
{
	//test01();
	test03();//ok
	return 0;
}