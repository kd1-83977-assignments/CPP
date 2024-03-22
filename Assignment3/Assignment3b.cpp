#include<iostream>
using namespace std;

class Time{
    private:
        int h;
        int m;
        int s;

    public:
        Time(){
            h=12;
            m=00;
            s=00;
        }
        Time(int h,int m,int s){
            this->h=h;
            this->m=m;
            this->s=s;
            }


        int getHour(){
            return h;

        }
        int getMintue(){
            return m;

        }
        int getSeconds(){
            return s;

        }

        void setHour(int h1){
            h=h1;
        }
        void setMintue(int m1){
            m=m1;
        }
        void setSeconds(int s1){
            s=s1;
        }

        void printTime(){
            cout<<"HH:MM:SS="<<h<<" "<<m<<" "<<s<<endl;

        }

};

int main(){

        Time *ptr = new Time();

        ptr->printTime();

        Time *ptr2 = new Time(10,32,15);
        ptr2->printTime();

        cout<<"hour is "<<ptr2->getHour()<<endl;
        cout<<"Mintues is "<<ptr2->getMintue()<<endl;
        cout<<"Seconds is "<<ptr2->getSeconds()<<endl;

        ptr->setHour(10);
        cout<<"hour is "<<ptr->getHour()<<endl;

        ptr->setMintue(10);
        cout<<"Mintues is "<<ptr->getMintue()<<endl;

        ptr->setSeconds(10);
        cout<<"Seconds is "<<ptr->getSeconds()<<endl;

    return 0;
}