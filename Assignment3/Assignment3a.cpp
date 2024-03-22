#include<iostream>
using namespace std;

class Cylinder{
    private:
    double vol;
    static const double Pi; 
    int radius;
    const int height;

    public:
    Cylinder() :height(12)
    {
        radius=10;

    }

    Cylinder(int r, int h):height(h)
    {
            radius= r;
            
    }

    void setRadius(int r1)
    {
        radius= r1;
    }

    int getRadius()
    {
        return radius;
    }
    int getHeight() const
    {
        return height;
    }

    double getVolume(){
        return vol;
    }
    void displayVolume(){
        vol = radius*height*radius*Pi;
        cout<<vol<<" is the volume"<<endl;
    }


};

const double Cylinder::Pi=3.14;




int main(){

    Cylinder c1;
    Cylinder c2(10,20);

    c1.displayVolume();
    c2.displayVolume();

    cout<<"radius is :"<<c1.getRadius()<<endl;
    cout<<"height is :"<<c1.getHeight()<<endl;

    c1.setRadius(20);

    cout<<"radius is after update :"<<c1.getRadius()<<endl;


    return 0;
}