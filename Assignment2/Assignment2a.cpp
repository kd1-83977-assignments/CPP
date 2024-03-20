#include<iostream>
using namespace std;

class Volume {
    private:

    int len;
    int brdth;
    int hght;
   

    public:
    Volume(){

        len = 10;
        brdth=10;
        hght=10;

    }
    Volume(int value){
        this->len= value;
        this->brdth=value;
        this->hght=value;

    }

    Volume(int l, int b, int h){

        this->len= l;
        this->brdth= b;
        this->hght= h;

       
    }

    void printVolume(){

        int volume= this->len*this->brdth*this->hght;
        cout<<"Volume is"<<volume;


    }
};


int main(){


        int choice;

        Volume v1;
        Volume v2(8);
        Volume v3(8,7,6);

        do{

        
        cout<<"Enter for 1 to Calc default volume"<<endl;
        cout<<"Enter for 2 to Calc volume for equal side"<<endl;
        cout<<"Enter for 3 different sides"<<endl;
        cout<<"Enter to 0 exit"<<endl;

       cout<<"enter the choice";

        cin>>choice;
        
            switch(choice){



        case 0: 
            cout<<"thank you";
            break;


         case 1:   
        
        v1.printVolume();
            break;
         case 2:
        v2.printVolume();
            break;
         case 3:
        v3.printVolume();
            break;
            default:
            cout<<"Wrong option";
            break;
            
        }
        }while(choice !=0);


    return 0;
}