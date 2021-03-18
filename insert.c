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

void insert_sort(int a[]){
    int tmp,i,j,k;
    for(i=1;i<SIZE;i++){
        if(a[i]<a[0]){
            tmp=a[i];
            for(k=i;k>0;k--){
                a[k]=a[k-1];
            }
            a[0]=tmp;
        }
        else if(a[i]<a[i-1]){
            for(j=i-1;j>=0;j--){
                if(a[j]<a[i]){
                    tmp=a[i];
                    for(k=i;k>j+1;k--){
                        a[k]=a[k-1];
                    }
                    a[j+1]=tmp;
                    j=0;
                }
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
    insert_sort(a);
    show(a);
}
