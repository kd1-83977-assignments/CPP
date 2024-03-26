#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    double salary;

    public:
        Employee(){
            id=0;
            salary=0;
            cout<<"Inside Employee parameterless constructor"<<endl;
        }

        Employee(int id, double salary){
            this->id=id;
            this->salary=salary;

            cout<<"Inside Employee parameterized constructor"<<endl;

        }
        void setID(int newId){
            id = newId;

        }
        int getId(){
            return id;

        }
        void setSalary(double newSal)
        {
            salary=newSal;

        }
        double getSalary(){

            return salary;
        }

        virtual void accept()
        {
            cout<<"enter emp id"<<endl;
            cin>>id;
            cout<<"enter emp salary"<<endl;
            cin>>salary;

        }
        virtual void display(){
            cout<<"emp id : "<<id<<endl;
            cout<<"emp sal :"<<salary<<endl;
        }
        virtual ~Employee(){
            cout<<"Inside Employee destructor"<<endl;
        }
};

class Manager: virtual public Employee
{
    private:
        double bonus;

    public:
        Manager(){
            bonus=1000;
            cout<<"Inside Manager parameterless constructor"<<endl;

        }
        Manager(int id, double salary,double bonus):Employee(id,salary)
        {
            this->bonus=bonus;
            cout<<"Inside Manager parameterized constructor"<<endl;
            
        }
        void setBonus(double newBonus){
            
            bonus=newBonus;

        }
        double getBonus(){
            return bonus;
        }
        void accept()
        {
            Employee::accept();
            acceptManager();
            
        }
        void display()
        {
            Employee::display();
            displayManager();

        }
        void acceptManager(){

            cout<<"enter bonus "<<endl;
            cin>>bonus;
        }

        void displayManager(){

            cout<<"bonus is :"<<bonus<<endl;

        }
        ~Manager(){
            cout<<"Inside Manager destructor"<<endl;
        }
};
class Salesman: virtual public Employee
{
    private:
        double comm;

    public:
        Salesman(){
            comm=10;
            cout<<"Inside Salesman parameterless constructor"<<endl;

        }
        Salesman(int id, double salary,double bonus):Employee(id,salary)
        {
            this->comm=comm;
            cout<<"Inside Employee parameterized constructor"<<endl;
            
        }
        void setCommission(double newComm){
            
            comm=newComm;

        }
        double getCommission(){
            return comm;
        }
        void accept()
        {
            Employee::accept();
            acceptSalesman();

        }
        void display(){

            Employee::display();
            displaySalesman();

        }
        void acceptSalesman(){

            cout<<"enter commission"<<endl;
            cin>>comm;
        }
        void displaySalesman(){

            cout<<"commission is"<<comm<<endl;
        }
        ~Salesman(){
            cout<<"Inside Salesman destructor"<<endl;
        }
};
class SalesManager:public Salesman,public Manager{
    public:
        SalesManager(){
            cout<<"Inside Salesmanager parameterless constructor"<<endl;
        }
         SalesManager(int id, double salary,double bonus,double comm): Employee(id,salary),Manager(id,salary,bonus),Salesman(id,salary,comm)
         {
            cout<<"Inside Employee parameterized constructor"<<endl;

         } 
        void accept(){

            Employee::accept();
            Manager::acceptManager();
            Salesman::acceptSalesman();
        }
        void display(){
            Employee::display();
            Manager::displayManager();
            Salesman::displaySalesman();
        }
        ~SalesManager(){
            cout<<"Inside SalesManager destructor"<<endl;
        }
};

int main(){
    int choice;
    int index = 0;
    Employee *arr[10];

    int countManager=0;
    int countSalesman=0;
    int countSalesManager=0;

    do{
        cout<<"0 to exit"<<endl;
        cout<<"1 to Accept Employee wrt designation"<<endl;
        cout<<"2 to count of Employee w.r.t designation"<<endl;
        cout<<"3 to display all Managers"<<endl;
        cout<<"4 to display all Salesman"<<endl;
        cout<<"5 to display all Salemanager"<<endl;
        cout<<"enter choice"<<endl;
        cin>>choice;

        switch(choice){

            case 0:
                cout<<"thank youu..."<<endl;
                break;
            case 1:
                int choice1;
                
                cout<<"1 to Accept Employee"<<endl;
                cout<<"2 to Accept Manager"<<endl;
                cout<<"3 to Accept Salesman"<<endl;
                cout<<"4 to Accept SalesManger"<<endl;
                cin>>choice1;
                switch(choice1){
                    case 0:
                        cout<<"continue"<<endl;
                    case 1:
                    if(index < 10)
                        arr[index]=new Employee();
                        arr[index]->accept();
                        index++;
                    
                    else
                    cout << "Array is Full..." << endl;
                    break;
                    case 2:
                    if(index < 10)
                        arr[index]=new Manager();
                        arr[index]->accept();
                        index++;
                        countManager++;
                    else
                    cout << "Array is Full..." << endl;
                    break;

                    case 3:
                    if(index < 10)
                        arr[index]=new Salesman();
                        arr[index]->accept();
                        index++;
                        countSalesman++;
                    else
                    cout << "Array is Full..." << endl;
                    break;
                    case 4:
                    if(index < 10)
                        arr[index]=new SalesManager();
                        arr[index]->accept();
                        index++;
                        countSalesManager++;
                    else
                    cout << "Array is Full..." << endl;
                    break;
                }
                
                break;
            case 2:
                cout<<"total Managers :"<<countManager<<endl;
                cout<<"total Salesman :"<<countSalesman<<endl;
                cout<<"total SalesManagers :"<<countSalesManager<<endl;

            case 3:
                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Manager))
                    arr[i]->display();
                break;
            
            case 4:

                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Salesman))
                    arr[i]->display();
                break;

            case 5:

                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(SalesManager))
                    arr[i]->display();
                break;
                           
        }

    }while(choice != 0);
  
    return 0;
}