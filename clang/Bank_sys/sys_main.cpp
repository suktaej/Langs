#include<iostream>
#include<cstring>
#include<cctype>

#define NAME_LEN 20
#define ACC_NUM 100

using namespace std;

void Menu_view(void);
void Make_account(void);
void Deposit(void);
void Withdrow(void);
void Acc_info(void);

void ID_check(int* id);

/*typedef struct{
    int user_id;
    int balance;
    char user_name[NAME_LEN];
} Account;*/

class Account
{
private:
    int user_id;
    int balance;
    char *user_name;

public:
    Account(int id,int money,char *name):user_id(id),balance(money)
    {
        user_name=new char[strlen(name)+1];
        strcpy(user_name,name);
    }

    Account(const Account &ref):user_id(ref.user_id),balance(ref.balance)
    {
        user_name=new char[strlen(ref.user_name)+1];
        strcpy(user_name,ref.user_name);
    }

    int Get_ID(void)    
    {
        return user_id;
    }
    char* Get_name(void)
    {
        return user_name;
    }
    int Get_balance(void)
    {
        return balance;
    }

    void Inputmoney(int money)
    {
        balance+=money;
    }
    void Outputmoney(int money)
    {
        balance-=money;
    }

    void Showinfo()
    {
        cout<<"ID:"<<user_id<<endl
        <<"Name:"<<user_name<<endl
        <<"Balnace:"<<balance<<endl<<endl;
    }
    ~Account()
    {
        delete []user_name;
    }
};

Account *account_arr[ACC_NUM];
int acc_count=0;

enum {MAKE=1, DEPOSIT, WITHDROW, INQUIRE, EXIT};

void Menu_view(void){

    cout<<"1.Make account "<<endl
    <<"2.Deposit"<<endl
    <<"3.Withdraw"<<endl
    <<"4.Account info"<<endl
    <<"5.Exit"<<endl;
    cout<<endl;
}

void Make_account(void){

    int money=0;
    char name[NAME_LEN];

    cout<<"[Make Account]"<<endl;
    cout<<"Name:";
    cin>>name;
    cout<<"Amount of deposit(default balance:0):";
    cin>>money;
    cout<<endl;

    /*account_arr[acc_count].user_id=acc_count;
    account_arr[acc_count].balance=money;
    strcpy(account_arr[acc_count].user_name,name);

    cout<<"Your accout open"<<endl<<"Your ID:"<<account_arr[acc_count].user_id<<endl
    <<"Name:"<<account_arr[acc_count].user_name<<endl<<"Balance:"<<account_arr[acc_count].balance<<endl;
    cout<<endl;
    acc_count++;*/

    account_arr[acc_count]=new Account(acc_count,money,name);
    account_arr[acc_count++]->Showinfo();
}

void Deposit(void){

    int id;
    int money=0;

    cout<<"[Deposit]"<<endl;

    ID_check(&id);

    while(1)
    {
        cout<<"Enter amount of deposit:";
        cin>>money;

        if(!cin)
        {
            cout<<endl;
            cout<<"Please check input data"<<endl;
            cin.clear();
            fseek(stdin,0,SEEK_END);    //while(cin.get()!='\n')
        }
        else if(money<0)
        {
            cout<<"Check input money"<<endl;    
        }
        else
        {
            /*cout<<endl;
            cout<<"Default your balance:"<<account_arr[id].balance<<endl;
            account_arr[id].balance+=money;
            cout<<"Now balance:"<<account_arr[id].balance<<endl;
            cout<<endl;*/
            account_arr[id]->Inputmoney(money);
            account_arr[id]->Showinfo();
            
            break;
        }
    }
}

void Withdrow(void){

    int money;
    int id;
    cout<<"[Withdrow]"<<endl;

    ID_check(&id);

    while(1)
    {
        cout<<"Enter amount of withdraw:";
        cin>>money;

        if(!cin)
        {
            cout<<"Please check input data"<<endl;
            cin.clear();
            fseek(stdin,0,SEEK_END);    //while(cin.get()!='\n')
        }
        else if(money<0)
        {
            cout<<"Check input money"<<endl;    
        }
        else if(account_arr[id]->Get_balance()<money)
        {
            cout<<"Not enough your balance"<<endl;
        }
        else
        {
            cout<<"Default your balance:"<<account_arr[id]->Get_balance()<<endl;
            account_arr[id]->Outputmoney(money);
            cout<<"Now balance:"<<account_arr[id]->Get_balance()<<endl;
            cout<<endl<<endl;
            break;
        }
    }
}

void Acc_info(void){

    int id;

    ID_check(&id);
    account_arr[id]->Showinfo();
}

void ID_check(int* id){

    while(1){

        cout<<"Enter your ID:";
        cin>>*id;

        if (cin.fail())
        {
            cout<<"Check your input data"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        else
        { 
            for(int i=0;i<acc_count;i++)
            {
                if(account_arr[i]->Get_ID()==*id)
                {
                    return;
                }
            }
            cout<<"Not exist ID"<<endl;
        }
    }
}

int main(void){

    int menu_select=0;

    while(1)
    {
        Menu_view();

        cout<<"select number:";
        cin>>menu_select;

        switch(menu_select)
        {
            case MAKE:
                Make_account();
                break;
            case DEPOSIT:
                Deposit();
                break;
            case WITHDROW:
                Withdrow();
                break;
            case INQUIRE:
                Acc_info();
                break;
            case EXIT:
                return 0;
            default:
                cout<<"illegal selection"<<endl;
        }
    }
}