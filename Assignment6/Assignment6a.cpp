#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    void acceptDate()
    {
        cout<<"enter day"<<endl;
        cin>>day;
        cout<<"enter month"<<endl;
        cin>>month;
        cout<<"enter year"<<endl;
        cin>>year;

    }
    void displayDate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }

};

class Person:{
    private:
        string name;
        string address;
        Date dob;

    public:

        virtual void acceptData(){
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter address"<<endl;
        cin>>address;
        cout<<"enter bithdate date "<<endl;
        dob.acceptDate();


        }
        virtual void displayData(){
        cout<<"person name is "<<name<<endl;
        cout<<"person's address "<<address<<endl;
        cout<<"Birthdate is ";
        dob.displayDate();
        }
    };

class Employee: public Person
{
private:
    int empid;
    string dept;
    double Salary;
    Date doj;

public:
   
    void acceptData()
    {
        cout<<"enter employee id"<<endl;
        cin>>empid;
        cout<<"enter employee sal"<<endl;
        cin>>Salary;
        cout<<"enter department"<<endl;
        cin>>dept;
        cout<<"enter joining date "<<endl;
        doj.acceptDate();

        Person::acceptData();

    }
    void displayData()
    {
        cout<<"employee id - "<<empid<<endl;
        cout<<"employee salary- "<<Salary<<endl;
        cout<<"employee department - "<<dept<<endl;
        cout<<"joining date is ";
        doj.displayDate();

        Person::displayData();
    }

};

int main(){
    // Date d1;
    Person p;
    p.acceptData();
    p.displayData();

    Employee e;
    e.acceptData();
    e.displayData();

    Person *ptr= new Employee;
    ptr->acceptData();
    ptr->displayData();
    delete ptr;
    ptr = NULL;
    return 0;
}