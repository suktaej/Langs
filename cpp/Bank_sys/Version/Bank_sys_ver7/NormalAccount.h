#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount:public Account
{
	protected:
		int interRate;
	public:
		//NormalAccount(int id,int money,char* name,int rate):Account(id,money,name),interRate(rate){}
		NormalAccount(int id,int money, std::string name, int rate):Account(id,money,name),interRate(rate){}
		virtual void Deposit(int money)
		{
			Account::Deposit(money);
			Account::Deposit(money*(interRate/100.0));
		}
		virtual void ShowInfo(void) const
		{
			std::cout<<"------[Normal ID]--------"<<std::endl;
			std::cout<<"ID:\t\t"<<AccID<<std::endl;
			std::cout<<"Name:\t\t"<<Customer_Name<<std::endl;
			std::cout<<"Balance:\t"<<Balance<<std::endl;
			std::cout<<"Rate:\t\t"<<interRate<<"%"<<std::endl;
			std::cout<<"------------------------"<<std::endl;
		}
};

#endif
