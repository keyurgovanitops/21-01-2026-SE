#include <stdio.h>

int addition(int a,int b);

int main(){
    int a = 10, b = 20;
    printf("%d",addition(a,b));
    return 0;
}
int addition(int a,int b){
    return a+b;
}
