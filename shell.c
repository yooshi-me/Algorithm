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

void shell_sort(int a[]){
    int tmp,i,j,k,h;
    h=17;
    while(h>0){
        for(i=0;i<SIZE-h;i++){
            for(j=i+h;j<SIZE;j=j+h){
                k=j;
                while(k>0&&a[k-h]>a[k]){
                     if(a[i]>a[j]){
                        tmp=a[i];
                        a[i]=a[j];
                        a[j]=tmp;
                    }   
                    k=k-h;
                }
            }
        }
        h=h-4;
    }
}

void main(){
    int a[SIZE];
    char x;
    set(a);
    show(a);
    shell_sort(a);
    printf("Sorted\n");
    show(a);
}