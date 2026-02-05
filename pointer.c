#include <stdio.h>

int main(){
    // pointer - a variable that stores another vairable's address
    int a = 6;
    int *p;
    p = &a;

    int arr[5] = {1,2,3,4,5};


    printf("%d", *arr);
    printf("%d", arr[0]);
    printf("%d",0[arr]);

    
    printf("%d", *(arr+3));


    return 0;
}