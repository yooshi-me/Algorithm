#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

void show(int a[]){
    int count=0;
    for(int i=0;i<SIZE;i++){
        count++;
        printf("%4d ",a[i]);
        if(count==10){
            printf("\n");
            count=0;
        }
    }
    printf("\n");
}

void set(int a[]){
    int j,i,no;
    for(i=0;i<SIZE;i++)
    {
        srand((unsigned)time(NULL));
        no=rand()%(SIZE*10);
        j=0;
        while(j<i){
            if(a[j]==no){
                no=rand()%(SIZE*10);
                j=0;
            }
            j++;
        }
        a[i]=no;
    }
}

void bubble_sort(int a[]){
    int tmp;
    for(int i=0;i<SIZE;i++){
        for(int j=i+1;j<SIZE;j++){
            if(a[i]>a[j]){
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

void main(){
    int a[SIZE];
    char x;
    set(a);
    show(a);
    printf("Sorted\n");
    bubble_sort(a);
    show(a);
}
