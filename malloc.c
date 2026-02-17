#include <stdio.h>
#include <stdlib.h>

int* arrayCreator(int size)
{
    int *arr = malloc(size * sizeof(int));
    printf("Enter the numbers in array:- \n");
    int totalSize = size*sizeof(int);
    int intsize = sizeof(arr[0]);
    for(int i=0; i<(totalSize/intsize); i++){
        scanf("%d", &arr[i]);
    }
    return arr;
}

void arrayPrinter(int *arr,int size)
{
    printf("\n");
    printf("This is the output:- \n");
    for(int i=0;i<size;i++){
        printf("%d \n",arr[i]);
    }
}

int main()
{
    int n;
    printf("enter size\n");
    scanf("%d",&n); 
    int* arr = arrayCreator(n);
    arrayPrinter(arr,n);
    return 0;
}

// create first array with malloc 
// create another array with calloc
// print the first array(malloc one) without initializing it.
// print the second array(calloc one) without initializing it.
