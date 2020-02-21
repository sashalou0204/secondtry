#include <iostream>
using namespace std;

class A
{
private:
	A()
	{
		a = new A;//�ͣ��¶�����
	}
public:
	static A* getInstance()
	{
		return a;//����ӿڣ�ʹ�ö���ɻ��
	}
private:
	static A* a; 
};


A* A::a = NULL;

	//ʵ�ֵ����Ĳ��裺
	//1.���캯��˽�л�
	//2. ���Ӿ�̬����˽�еĵ�ǰ���ָ�����
	//3. �ṩһ����̬�Ķ���ӿڣ��������û���õ�������




//�����ַ�Ϊ�� ����ʽ������ʽ

//��
class SingleCase_lazy
{
private:
	SingleCase_lazy(){}//�ڹ��캯������û�г�ʼ����
	//�ⲿ�ӿں���
public:
	static SingleCase_lazy* getInstance()
	{
		if(pSingleCase == NULL)
		{
			//��һ�ε���֮��Żᴴ��
			pSingleCase = new SingleCase_lazy;
		}
		return pSingleCase;
	}
private:
	static SingleCase_lazy* pSingleCase;

};
//�����ʼ��
SingleCase_lazy*SingleCase_lazy::pSingleCase = NULL;


//��
class SingleCase_hungry
{
private:
	SingleCase_hungry(){cout<<"���Ƕ���ʽ�Ĺ��캯��"<<endl;}
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
		//Σ��,��Ϊֻ��һ������һɾ��û��
//��ʵû��Ҫ�����ͷ��ڴ������
	}
			
private:
	static SingleCase_hungry* pSingleCase;

};
SingleCase_hungry* SingleCase_hungry::pSingleCase = new SingleCase_hungry;//��main��������ǰ�ʹ�������


//�̰߳�ȫ���⣬����ʽ�̲߳���ȫ������ʽok

void test01()
{
	SingleCase_lazy* p1 = SingleCase_lazy::getInstance();
	SingleCase_lazy* p2 = SingleCase_lazy::getInstance();
	if(p1 == p2)
	{
		cout<<"����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���"<<endl;
	}
	else
	{
		cout<<"���ǵ���ģʽ"<<endl;
	}

	SingleCase_hungry* p3 = SingleCase_hungry::getInstance();
	SingleCase_hungry* p4 = SingleCase_hungry::getInstance();
	if(p3 == p4)
	{
		cout<<"����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���"<<endl;
	}
	else
	{
		cout<<"���ǵ���ģʽ"<<endl;
	}

}

/*
void test02()
{
	SingleCase_hungry::freeSpace();//�ͷ�
}*/

int main01(void)
{
	//cout<<"��ʼ����main����"<<endl;
	//A::getInstance();
	test01(); //ok


	return 0;
}
