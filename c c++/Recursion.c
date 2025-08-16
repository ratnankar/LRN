#include<stdio.h>

int factorial(int m){

    if(m == 0){

        return 1;

    }

    else{

        return m*factorial(m-1);
    }
}

int main(){

    int n;

    printf("Enter the number : ");
    scanf("%d", &n);

    int a = factorial(n);

    printf("Factorial : %d",a);

}