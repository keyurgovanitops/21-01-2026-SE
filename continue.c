#include <stdio.h>
void main()
{
    int i=0;
    int arr[5] = {18,19,16,45,36};
    while(i<5){
        if(arr[i]<18){
            i++;
           continue;
        }
        printf("%d",arr[i]);
        i++;
    }
    
}