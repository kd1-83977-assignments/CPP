#include<iostream>
using namespace std;


class tollbooth{
    unsigned int nocar;
    double total;
    float count;

    public:
    tollbooth(){
        nocar=0;
        total=0;
        count = 0;


    }
    void payingCar(){

        cout<<"car entered  ";

        nocar= nocar+1;
        total= total+ 0.50;
        cout<<nocar<<" - rs"<<total<<endl;

        float count = total/0.5;




    }

    void nopayCar(){

        cout<<"car entered without paying";
        nocar= nocar +1;
        cout<<nocar<<endl;


    }
    void printOnConsole(){

        cout<<"number of cars "<<nocar<<"total cash "<<total<<endl;

        cout<<"number of cars paying toll "<<count<<endl;

        cout<<"number of cars paying toll "<<nocar-count<<endl;

    }


};


int main(){

    int choice;

    tollbooth t1;


    do{
        cout<<"Enter for 1 to enter car paying toll "<<endl;
        cout<<"Enter for 2 to enter car without paying toll"<<endl;
        cout<<"total cars passed and total toll collected"<<endl;
        cout<<"Enter to 0 exit"<<endl;

       cout<<"enter the choice";
       cin>>choice;

       switch(choice){
            case 0:
            cout<<"thank you";
            break;

            case 1:
            t1.payingCar();
            break;

            case 2:
            t1.nopayCar();
            break;

            case 3:
            t1.printOnConsole();
            break;

            default:
            cout<<"wrong choice entered";
            break;

       }
    }while(choice !=0);



    return 0;
}