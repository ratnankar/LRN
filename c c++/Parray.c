#include<stdio.h>
void input(int**, int, int*);
void display(int**, int, int*);

int main(){

    int* p[3];

    int a[3],b[4],c[3];

    int size[3] = {3,4,3};

    p[0] = a;
    p[1] = b;
    p[2] = c;

    input(p,3,size);

    display(p,3,size);

}

void input(int **n,int a, int *s){

    printf("Enter the values :\n");

    for(int i = 0; i<a; i++){

        for(int j = 0; j<s[i]; j++){

            printf("a%d%d = ",i,j);
            scanf("%d",*(n+i)+j);

        }

    }

}

void display(int **m,int b, int *k){

    printf("\nThe values are :\n");

    for(int i = 0; i<b; i++){

        for(int j = 0; j<k[i]; j++){

            printf("a%d%d = %d",i,j,*(*(m+i)+j));

            if(j != k[i]-1){

                printf(", ");

            }

        }

        printf("\n");

    }

    printf("\n");

}