#include<iostream>
using namespace std;

class Product{
    private:
int id;
string title;
double price;
    public:
virtual void accept(){
    cout<<"enter product id"<<endl;
    cin>>id;
    cout<<"enter product name"<<endl;
    cin>>title;
    cout<<"enter product price"<<endl;
    cin>>price;
}
    
    void setPrice(double newPrice){  //setter
        price=newPrice;
    }

    double getPrice(){    //getter
            return price;
    }

    virtual void display(){

    cout<<"product ID is "<<id<<endl;
    cout<<"product title is "<<title<<endl;
    cout<<"product price is "<<price<<endl;

}
};


class Book : public Product
{
    private:
string author;
    public:
void accept(){
    cout<<"enter author"<<endl;
    cin>>author;
    Product::accept();

    setPrice(getPrice()*.90);

}

virtual void display(){
    cout<<"author is"<<author<<endl;
    Product::display();

}
};


class Tape : public Product{
    string artist;
void accept(){
    cout<<"enter artist"<<endl;
    cin>>artist;
    Product::accept();

    setPrice(getPrice()*.95);

}

virtual void display(){
    cout<<"artist is"<<artist<<endl;
    Product::display();

}
};


int main(){
    Product *arr[3];
    //Product *s= NULL;
    int index=0;
    double totalBill = 0;
    // arr[0]=new Tape();
    // arr[1]=new Book();
    // arr[2]=new Tape();

    int choice;

    do{
        cout<<"Enter 0 to Exit "<<endl;
        cout<<"Enter 1 to buy a book"<<endl;
        cout<<"Enter 2 to buy a tape "<<endl;
        cout<<"Enter 3 to calculate bill"<<endl;
        cout<<"Enter choice"<<endl;
        cin>>choice;

        switch(choice){
            case 0:
            cout<<"Thank you"<<endl;
            break;
            case 1:
            if (index < 3) {
                arr[index] = new Book(); //upcasting
                arr[index]->accept();
                index++;
            }

            
            break;
            case 2:
            if (index < 3) {
                arr[index] = new Tape(); //upcasting
                arr[index]->accept();
                index++;
            }
            
            break;
            case 3:
                
            for (int i = 0; i < index; i++) {
                arr[i]->display();
                totalBill += arr[i]->getPrice();
            }
            cout<<"total bill "<<totalBill<<endl;
            break;
            default:
            cout<<"Wrong choice"<<endl;
            break;

        }

    }while(choice != 0);

    for(int i=0; i<index; i++){
        delete arr[i];
        arr[i] = NULL;
    }


    return 0;
}