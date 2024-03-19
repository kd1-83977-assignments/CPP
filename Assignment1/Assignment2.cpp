#include<iostream>

using namespace std;
struct date {
   int sd;
   int sm;
   int sy;
  
  
    void initDate(){
        int d=1,m=2,y=2000;
        // sd = d;
        // sm = m;
        // sy = y;
        cout<<"Date month and year " <<d<<" - "<<m<<" - "<<y<<endl;

    }
    void printDateOnConsole(){
       cout<<sd<<" - "<<sm<<" - "<<sy<<endl;
    }

    void acceptDateFromConsole(){
        cin>>sd>>sm>>sy;
        
    }
   
    bool isLeapYear(){
        
        bool isLeap=false;
        if((sy%4 == 0 and sy % 100 != 0) || ( sy% 400 == 0) ){
            isLeap=true;
            cout<<"is a leap year"<<endl;
        }
       else{
            cout<<"not a leap year"<<endl;
        
       }
       
     return isLeap; 
    }
};
int main(){
    struct date t;
    int ch;
    
    do{
        cout<<"1 To view default Date"<<endl;
        cout<<"2 print Date"<<endl;
        cout<<"3 accept Date"<<endl;
        cout<<"4 Leap Year"<<endl;
        cout<<"enter choice"<<endl;
        cout<<"0 end"<<endl;
        cin>>ch;
        switch(ch){
            case 0:
            cout<<"exit"<<endl;
            break;
            case 1:
            t.initDate();
            break;
            case 2:
            t.printDateOnConsole();
            break;
            case 3:
            t.acceptDateFromConsole();
            break;
            case 4:
            t.isLeapYear();
            break;


            default:
            cout<<"wrong option"<<endl;
            break;

        
        }
    }
    while(ch !=0);
    return 0;

}