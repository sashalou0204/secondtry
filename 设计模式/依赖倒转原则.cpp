#include<iostream>
using namespace std;


#if 0
class BankWorker
{
public:
	void saveService()
	{
		cout<<"存款..."<<endl;
	}
	void payService()
	{
		cout<<"支付..."<<endl;
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
//一层依赖一层
#endif


//首先第一个worker类职责太多


 class AbstractWorker
 {
 public:
	 virtual void doBusiness() = 0;//工作人员干活
 };
 //专门存款的工作人员

 class SaveBankWorker : public AbstractWorker
 {
 public:
	 virtual  void doBusiness()
	 {
		 cout<<"存款..."<<endl;
	 }
 };

 class PayBankWorker : public AbstractWorker
 {
 public:
	 virtual  void doBusiness()
	 {
		 cout<<"付款..."<<endl;
	 }
 };

 //第一层结束，分开

 void doMyBusiness(AbstractWorker* worker)//依赖于抽象层，传进来是办什么业务的人就办什么业务
 {
	 worker->doBusiness();
 }
 //中间层


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