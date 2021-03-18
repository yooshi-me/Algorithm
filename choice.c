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

void choice_sort(int a[]){
    int i,j,index,mini,tmp;
    for(i=0;i<SIZE;i++){
        mini=a[i];
        index=i;
        for(j=i;j<SIZE;j++){
            if(a[j]<mini){
                mini=a[j];
                index=j;
            }
        }
        tmp=a[i];
        a[i]=a[index];
        a[index]=tmp;
    }
}

void main(){
    int a[SIZE];
    char x;
    set(a);
    show(a);
    printf("Sorted\n");
    choice_sort(a);
    show(a);
}
