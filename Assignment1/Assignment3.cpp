#include<iostream>

using namespace std;
class student {
   int roll_no;
   string name;
   int mks;
  
  public:
    void initStudent(){
        int roll_no=0;
        string name="default name";
        mks=00;
      cout<<"Student details " <<roll_no<<" - "<<name<<" - "<<mks<<endl;

    }
    void printStudent(){
       cout<<roll_no<<" - "<<name<<" - "<<mks<<endl;
    }
    
    void acceptStudent(){
        cin>>roll_no>>name>>mks;
        
    }
   
};
int main(){
    struct student st;
    int ch;
    
    do{
        cout<<"1 To view default details"<<endl;
        cout<<"2 print student details"<<endl;
        cout<<"3 accept students details"<<endl;
        cout<<"0 end"<<endl;
        cout<<"enter choice"<<endl;
       
        cin>>ch;
        switch(ch){
            case 0:
            cout<<"exit"<<endl;
            break;
            case 1:
            st.initStudent();
            break;
            case 2:
            st.printStudent();
            break;
            case 3:
            st.acceptStudent();
            break;
           
            default:
            cout<<"wrong option"<<endl;
            break;

        
        }
    }
    while(ch !=0);
    return 0;

}