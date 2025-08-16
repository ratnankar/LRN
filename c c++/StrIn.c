#include<stdio.h>
int length(char*, int);

int main(){

    char str[10];

    printf("Enter your name : ");

    fgets(str,10,stdin);

    int len = length(str,10);

    printf("Length of your name : %d",len);

    // len = length(str,10);

    // printf("\nLength of str = %d",len);

}

int length(char* s,int n){

    int l;


    for(int i = 0; s[i] && i<n; i++){

        l = i;

    }

    s[l] = '\0';

    return l;

}