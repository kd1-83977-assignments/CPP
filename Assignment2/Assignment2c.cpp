#include<iostream>

using namespace std;

class Address{
    private:
    string building;
    string street;
    string city;
    int pin;

    public:
    Address(){
        building="sunbeam";
        street="shanivar peth";
        city="karad";
        pin=415016;

    }
    Address(string building,string street,string city,int pin){
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }

    void setBuilding(string building){
        this->building=building;
    }

     void setStreet(string street){
        this->street=street;
    }
     void setCity(string city){
        this->city=city;
    }
     void setPin(int pin){
        this->pin=pin;
    }

    string giveBuilding(){
        return building;
    }

    string giveStreet(){
        return street;
    }
    string giveCity(){
        return city;
    }
    int givePin(){
        return pin;
    }

    void accept(){

        cout<<"enter 1.building,2.street,3.city,4.pin"<<endl;
        cin>>building>>street>>city>>pin;

    }

    void display(){

        cout<<"Building is "<<building<<" street is "<<street<<" city is "<<city<<" pin "<<pin<<endl;
        
    }


};



int main(){

    Address a1;
    a1.accept();

    Address a2("cz","yerwada","pune",411006);
    
    a2.display();



    return 0;
}