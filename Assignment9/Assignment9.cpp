#include<iostream>
#include <vector>
using namespace std;


enum Eaccounttype{
    SAVING =1,
    CURRENT ,
    DMAT 
};
class InsufficientFundsException
{
private:
    int accno;
    double currentBalance;
    double withdrawAmount;
public:
void display()
{
    if(currentBalance<withdrawAmount){
    cout << "Expection!!!!! Insufficient Balance" << endl;
    }

    else if(withdrawAmount<0)
    { 
        cout << "Exception!!!!Cannot withdraw value less than 0 " << endl;
    }

}
InsufficientFundsException()
{

}
InsufficientFundsException(int accno,double currentBalance,double withdrawAmount)
{
    this->accno=accno;
    this->currentBalance=currentBalance;
    this->withdrawAmount=withdrawAmount;
      
}

};


class Account
{
private:
    const int accno;
    Eaccounttype type;
    double balance;
    static int generateno;

public:
    Account():accno(++generateno)
    {
        
    }
    int getaccountNo()
    {
        return accno;
    }
    int getBalance()
    {
        return balance;
    }
    
    Account(Eaccounttype type,double balance):accno(++generateno)
    {
        //this->accno=accno;
        this->type=type;
        this->balance=balance;

    }
    void accept()
    {
        int ch;
        //cout<<"Enter Acc No:"<<endl;
        //cin>>accno;
        cout<<"Enter Balance:"<<endl;
        cin>>balance;
       
        cout<<"Enter Account Type:\n1.Saving\n2.Current\n3.Dmat"<<endl;
        cin>>ch;
        type=Eaccounttype(ch);
        
    }
    void display()
    {
        string Accounttype;
        cout<<"-----Account Details-----"<<endl;
        cout<<"Acc No:"<<accno<<endl;
        
        switch (type)
        {
        case 1: Accounttype="SAVING";
            break;
        case 2:Accounttype="CURRENT";
            break;
        case 3:Accounttype="DMAT";
            break;
        
        default:
            break;
        }
        cout<<"AccountType:"<<Accounttype<<endl;
        cout<<"Balance:"<<balance<<endl;

    }
    void deposit(double amount)
    {
    
        

         if(amount<0)
            throw 1;
        else{
        balance=amount+balance;
        }

    }
    void withdraw(double amount)
    {
        
        
        if(balance<amount)
           
        {   
            throw InsufficientFundsException(accno,balance,amount);
        }
        else if(amount<0)
        {   
            throw InsufficientFundsException(accno,balance,amount);
        }
        else{
        balance=balance-amount;
        }
        
    

    }
    
};

int Account :: generateno = 0;
int main()
{
    int choice;
    int index=0;
    vector <Account* > accountList;
    Account* ptr;
    //Account *ptr[5];
    //Account a1;
    //a1.display();
    
    do
    {
        cout<<"-------Welcome to Banking System-----------"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Add Account details"<<endl;
        cout<<"2.Display Account details"<<endl;
        cout<<"3.Deposit money"<<endl;
        cout<<"4.Withdraw money"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0: cout<<"---------Thank you for using Bank--------------------"<<endl;
                    break;

            case 1: 
                    ptr=new Account();
                    ptr->accept();
                    accountList.push_back(ptr);
                    /*if(index<5)
                    {
                        ptr[index]=new Account();
                        ptr[index]->accept();
                        index++;
                    }
                    else{
                        cout<<"Array is full"<<endl;
                    }*/
                    break;
            case 2: 
                    for(int i=0;i<accountList.size();i++)
                    {
                        accountList[i]->display();
                    }

                    /*for(int i=0;i<index;i++)
                    {
                        ptr[i]->display();
                    }*/
                    break;
            case 3: {
                    int amount,accountno;
                        cout<<"Enter Accountno:"<<endl;
                        cin>>accountno;
                        
                   // for(int i=0;i<index;i++)
                   for(int i=0;i<accountList.size();i++)
                    {
                        try{
                        
                        //if(ptr[i]->getaccountNo()==accountno)
                        if(accountList[i]->getaccountNo()==accountno)
                        {
                            cout<<"Available Balance:"<<accountList[i]->getBalance()<<endl;
                        cout<<"Enter Amount to deposit:"<<endl;
                        cin>>amount;
                         accountList[i]->deposit(amount);
                        // ptr[i]->deposit(amount);
                        }
                         }
                         catch(int)
                        {
                            cout << "!!!!!!!!!!!!!!!!!!!Exception !!!!!!!!!!!! \nInvalid Amount to deposit" << endl;
                        }
                       
                    }
            }
                            break;
            case 4: 

                        int amount,accountno;
                        cout<<"Enter Accountno:"<<endl;
                        cin>>accountno;
                        
                    //for(int i=0;i<index;i++)
                    for(int i=0;i<accountList.size();i++)
                    {
                        try{
                        
                       // if(ptr[i]->getaccountNo()==accountno)
                        if(accountList[i]->getaccountNo()==accountno)
                        {
                        cout<<"Available Balance:"<<accountList[i]->getBalance()<<endl;
                        cout<<"Enter Amount to withdraw:"<<endl;
                        cin>>amount;
                       // ptr[i]->withdraw(amount);
                        accountList[i]->withdraw(amount);
                        }
                        }
                        catch(InsufficientFundsException e)
                        {
                            e.display();
                        }
                       
                    }
                    break;

                default: cout<<"Invalid Choice!!!!!!!!!!"<<endl;
                
                        break;
            
        }
    } while (choice!=0);

    for(int i=0;i<accountList.size();i++)
    {
        delete accountList[i];
    }
    
    /*for (int i = 0; i < index; i++)
        delete ptr[i];*/
    return 0;
}