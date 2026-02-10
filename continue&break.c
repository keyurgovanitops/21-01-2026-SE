#include <stdio.h>
void main()
{
    int i=0;
    int arr[5] = {11,22,33,44,55};
    while(i<5)
    {
        if(arr[i]%2!=0) // 
        {
            i++;
            continue; // cotinue - skip // break - exit out of loop
        }
        printf("%d\n",arr[i]);
        i++;
    }
    printf("will this print?");
}