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

int ID_check(int id);

typedef struct{
    int user_id;
    int balance;
    char user_name[NAME_LEN];
} Account;

Account account_arr[ACC_NUM];
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

    account_arr[acc_count].user_id=acc_count;
    account_arr[acc_count].balance=money;
    strcpy(account_arr[acc_count].user_name,name);

    cout<<"Your accout open"<<endl<<"your ID:"<<account_arr[acc_count].user_id<<endl
    <<"Name:"<<account_arr[acc_count].user_name<<endl<<"Balance:"<<account_arr[acc_count].balance<<endl;
    cout<<endl;
    acc_count++;
}

void Deposit(void){

    int id;
    int money=0;

    cout<<"[Deposit]"<<endl;

    while(1){

        cout<<"Enter your ID:";
        cin>>id;

        if(ID_check(id)==0) 
        break;
        else
        { 
            cout<<"Check your ID"<<endl;
        }
    }

    cout<<"Welcome "<<account_arr[id].user_name<<endl
    <<"Enter amount of deposit:";

    while(1)
    {
        cin>>money;

        if(money>0)
        {
            cout<<endl;
            cout<<"Default your balance:"<<account_arr[id].balance<<endl;
            account_arr[id].balance+=money;
            cout<<"Now balance:"<<account_arr[id].balance<<endl;
            cout<<endl;
            break;
        }
        else
        {
            cout<<endl;
            cout<<"Please check input data"<<endl
            <<"Enter amount of deposit:";
        }
    }
}

int ID_check(int id){

    for(int i=0;i<ACC_NUM;i++)
    {
        if(account_arr[i].user_id==id)
            return 0;
    }
    return 1;
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
           /* case WITHDROW:
                Withdrow();
                break;
            case INQUIRE:
                Acc_info();
                break;*/
            case EXIT:
                return 0;
            default:
                cout<<"illegal selection"<<endl;
        }
    }
}