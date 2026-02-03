#include <stdio.h>

void main(){
    int choice;

    printf("1.credit cash\n");
    printf("2.debit cash\n");
    printf("3.change pin\n");
    printf("4.balance inquiry\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1 : printf("cash has been credited");
                break;
        case 2 : printf("cash has been debited");
                break;
        case 3 : printf("your pin has been changed");
                break;
        case 4 : printf("balance inquiry send successfully");
                break;
        default : printf("you have entered a wrong choice");
    };


}