#include<iostream>

struct Date{
    int day;
    int month;
    int year;

};

   void initDate(struct Date* ptrDate){

    ptrDate->day=8;
    ptrDate->month=12;
    ptrDate->year=2024;

    printf("Date default - %d-%d-%d",ptrDate->day,ptrDate->month,ptrDate->year);

   }



    void acceptDate(struct Date *ptrDate){
        printf("enter Day, Month. Year");
        scanf("%d,%d,%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);

    }

    void printDate(struct Date *ptrDate){
        printf("Date - %d,%d,%d",ptrDate->day,ptrDate->month,ptrDate->year);


    }
int main(){
        struct Date d1;

        printf("select your choice\n");
        printf("1 to view default date\n");
        printf("2 to Accept date\n");
        printf("3 to print Date\n");
        printf("0 to exit\n");
        int choice;
        do{
        scanf("%d",&choice);

    
            switch(choice){
            
            case 1:
                initDate(&d1);
                break;

            case 2:
                acceptDate(&d1);
                break;
            case 3:
                printDate(&d1);
                break;
            case 0:
                printf("thank you for using");
                break;

            default:
                printf("Wrong choice");
                break;
            }

        }while(choice != 0);

    return 0;
}

