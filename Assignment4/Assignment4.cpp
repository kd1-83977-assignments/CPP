#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *ptr;


    public:
        Stack(int size=5){
            this->size=size;
            top= -1;
            ptr= new int[size];

        }

        void push(int element){
            if(!isFull()){
                ptr[top] =element;
                top++;
            }
            else{
                cout<<"Stack is full ";
            }

        }
        void pop(){
            if(!isEmpty()){
                top--;

            }
            else
            {
                cout<<"Stack is empty";
            }

        }
        int peek(){
            return ptr[top];
        }

        bool isEmpty(){
           
                return top == -1;

        }
        bool isFull(){

                return top == (size-1);
        }
        void printStack(){

            for(int i =top-1; i>=-1; i--){
                
                cout<<ptr[i]<<" ,";
            }
            cout<<endl;

        }

        ~Stack(){
            delete[] ptr;
            ptr = NULL;

        }

};

int main(){
    int v;
    int choice;
    cout<<"enter stack size"<<endl;
    cin>>v;
    Stack s(v);
   // int choice2;

    do{
        cout<<"enter 0 to exit"<<endl;
        cout<<"enter 1 for push values"<<endl;
        cout<<"enter 2 to pop value"<<endl;
        cout<<"enter 3 to view top value"<<endl;
        cout<<"enter 4 to print values"<<endl;
        cout<<"enter the choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"enter value in stack"<<endl;
            int choice2;
            cin>>choice2;
            s.push(choice2);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.printStack();
                break;
            default:
                cout<<"wrong value entered"<<endl;

        }

    }while(choice !=0);

    return 0;
}