#include<iostream>
using namespace std;


#if 0
class BankWorker
{
public:
	void saveService()
	{
		cout<<"���..."<<endl;
	}
	void payService()
	{
		cout<<"֧��..."<<endl;
	}
};

void doSave(BankWorker* worker)
{
	worker->saveService();
}
void doPay(BankWorker* worker)
{
	worker->payService();
}

void test()
{
	BankWorker* worker = new BankWorker;
	doSave(worker);
	doPay(worker);
}
//һ������һ��
#endif


//���ȵ�һ��worker��ְ��̫��


 class AbstractWorker
 {
 public:
	 virtual void doBusiness() = 0;//������Ա�ɻ�
 };
 //ר�Ŵ��Ĺ�����Ա

 class SaveBankWorker : public AbstractWorker
 {
 public:
	 virtual  void doBusiness()
	 {
		 cout<<"���..."<<endl;
	 }
 };

 class PayBankWorker : public AbstractWorker
 {
 public:
	 virtual  void doBusiness()
	 {
		 cout<<"����..."<<endl;
	 }
 };

 //��һ��������ֿ�

 void doMyBusiness(AbstractWorker* worker)//�����ڳ���㣬�������ǰ�ʲôҵ����˾Ͱ�ʲôҵ��
 {
	 worker->doBusiness();
 }
 //�м��


 void test05()
 {
	 AbstractWorker* pay = new PayBankWorker;
	 doMyBusiness(pay);
 }
 int main()
 {
	 test05();

	 return 0;
 }