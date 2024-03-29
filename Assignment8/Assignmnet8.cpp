#include<iostream>
using namespace std;

class InSufficientFundsException{
    private:
        int accno;
        double currentBalance;
        double withdrawAmount;

    public:
        InSufficientFundsException(int accno, double currentBalance,double withdrawAmount){
            this->accno=accno;
            this->currentBalance=currentBalance;
            this->withdrawAmount=withdrawAmount;
        }

        void display(){
            cout<<"account number is "<<accno<<endl;
            cout<<"account balance is "<<currentBalance<<endl;
            cout<<"account number is "<<withdrawAmount<<endl;
        }

};
enum EAccountType {SAVING, CURRENT,DMAT};

class Account{
private:
        int accno;
        int accountType;
        double balance;
public:
    Account(){
        accno=0;
        balance=0;
    }
    Account(int accno, enum EAccountType, double balance){
        this->accno=accno;
        this->balance=balance;

    }
    void accept(){
        int choice1;
        cout<<"Enter Account Type 0 for SAVINGS, 1 for CURRENT, 2 for DMAT"<<endl;
        cin>>choice1;
        accountType=EAccountType(choice1);
        cout<<"Enter Account details -"<<endl;
        cout<<"Enter Account number :"<<endl;
        cin>>accno;
        cout<<"Enter Account Balance"<<endl;
        cin>>balance;
    }

    void display(){

        cout<<"Account number is :"<<accno<<endl;
        cout<<"Balance is :"<<balance<<endl;

    }
    void deposit(double amount){
        if (amount < 0) {
            throw invalid_argument("Negative amount cannot be deposited.");
        }
        balance +=amount;
        
    }
    void withdraw(double amount){
         if (balance < amount || amount < 0) {
            throw InSufficientFundsException(accno, balance, amount);
        }
        balance -= amount;

    }
    int getAccountNumber(){
        return accno;
    }
};

int main(){
    int index=0;
    Account *arr[5];
    int choice;
    
    do{
        cout<<"Enter 1 for Create Account"<<endl;
        cout<<"Enter 2 for Deposit Account"<<endl;
        cout<<"Enter 3 for withdraw Account"<<endl;
        cout<<"Enter 4 to display bank details"<<endl;
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"thank youu..."<<endl;
                break;
            case 1:
                arr[index]=new Account;
                arr[index]->accept();
                index++;
                break;
            case 2:
                int d;
                int accNum;
                cout<<"enter account number :";
                cin>>accNum;
                cout<<"enter amount to deposit :"<<endl;
                cin>>d;
                if(arr[index-1]->getAccountNumber() == accNum){
                arr[index-1]->deposit(d);
                break;
                }
            case 3:
            int w;
            int accNum1;
            cout<<"enter account number :";
            cin>>accNum1;
            cout<<"enter amount to withdraw :";
            cin>>w;
            if(arr[index-1]->getAccountNumber() == accNum1){
            arr[index-1]->withdraw(w);
            break;
            }
            case 4:
                int accNum2;
                cout<<"enter account number :";
                cin>>accNum2;
                if(accNum2 == arr[index-1]->getAccountNumber()){
                    arr[index-1]->display();
                }
                break;
            default :
            cout<<"wrong choice "<<endl;
            break;
                          
        }

    }while(choice !=0 );
    for(int i=0; i<index; i++){
        delete arr[i];
        arr[i] =  NULL;
    }

    return 0;
}