#include<iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int day, int month, int year)
    {
        cout << "Date Parameterized" << endl;
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter day - ";
        cin >> day;
        cout << "Enter month - ";
        cin >> month;
        cout << "Enter year - ";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person{
    private:
    string name;
    string address;
    Date birthdate;
    
    public:
    Person(){
        name="";
        address="";
        //birthdate.displayDate();

    }

    void acceptDetails(){
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter address"<<endl;
        cin>>address;
        cout<<"enter bithdate date "<<endl;
        birthdate.acceptDate();
    }

    void displayDetails(){
        cout<<"person name is "<<name<<endl;

        cout<<"person's address "<<address<<endl;
        cout<<"Birthdate is ";
        birthdate.displayDate();
    }

};

class Employee{
    private:
    int empid;
    double sal;
    string dept;
    Date d2;

    public:
        Employee(){
            empid=0;
            sal=0;
            dept="";
           // d2.displayDate();
            
        }

        void acceptEmployee(){

            cout<<"enter employee id"<<endl;
            cin>>empid;
            cout<<"enter employee sal"<<endl;
            cin>>sal;
            cout<<"enter department"<<endl;
            cin>>dept;
            cout<<"enter joining date "<<endl;
            d2.acceptDate();

            
        }
        void displayEmployee(){
            cout<<"employee id - "<<empid<<endl;
            cout<<"employee salary- "<<sal<<endl;
            cout<<"employee department - "<<dept<<endl;
            cout<<"joining date is ";
            d2.displayDate();

        }
};

int main(){
        Person p;
        p.acceptDetails();
        p.displayDetails();

        Employee e;
        e.acceptEmployee();
        e.displayEmployee();

    return 0;
}