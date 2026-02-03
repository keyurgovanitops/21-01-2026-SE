#include <stdio.h>

void main(){

    int arr[5] = {1,2,3,4,5};
    char str[5] = "hello"; 
    // float arr1[5] = {1.2,2.3,4.5,5.5,6.6};
    // char arr3[] = {'h','e','l','l','o'};
    // char s[5] = "hello";

    // printf("the total size of array:-%d\n",sizeof(arr));
    // printf("element size :- %d", sizeof(arr[0]));
    // sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<5;i++){
        printf("%c",str[i]);
    }

    printf("%s", str);



    // printf("%.2f", arr1[6]);
    
}