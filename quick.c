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

void quick_sort(int a[],int low,int high){
    if(high-low<=0){
        return;
    }
    int pivot,i=low,j=high,midl=(low+high)/2,tmp;
    pivot=a[midl];
    while(i!=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    }
    quick_sort(a,low,i-1);
    quick_sort(a,i+1,high);
}

void main(){
    int a[SIZE];
    char x;
    set(a);
    show(a);
    quick_sort(a,0,SIZE-1);
    printf("Sorted\n");
    show(a);
}