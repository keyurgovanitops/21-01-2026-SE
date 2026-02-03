// 365.2422
// leap year -> feabrary-> 29
// 100/4 = 25; // leap 
// 400 -> 100; 
//1 
//2
//3
// 4 -> leap year
//5
//6
//7
//8 -> leap year

// 3333 year 

#include <stdio.h>

void main(){
    int year = 2024;
    if(year%4 == 0){
        printf("it is a leap year");
    }else{
        printf("it is not a leap year");
    }
}

