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
    Employee e;
    e.accept();
    e.display();

    Manager m;
    m.accept();
    m.display();

    Salesman s1;
    s1.accept();
    s1.display();

    SalesManager s2;
    s2.accept();
    s2.display();

    Employee *eptr= new Employee();
    eptr->accept();
    eptr->display();
    delete eptr;
    //eptr = NULL;

    eptr= new Manager();
    eptr->accept();
    eptr->display();
    delete eptr;
    //eptr = NULL;

    eptr= new Salesman();
    eptr->accept();
    eptr->display();
    delete eptr;
   // eptr = NULL;

    eptr= new SalesManager();
    eptr->accept();
    eptr->display();
    delete eptr;
   // eptr = NULL;

    return 0;
}