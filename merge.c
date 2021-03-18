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

void merge_sort (int array[], int left, int right) {
  int i, j, k, mid;
  int work[SIZE];  // 作業用配列
  if (left < right) {
    mid = (left + right)/2; // 真ん中
    merge_sort(array, left, mid);  // 左を整列
    merge_sort(array, mid+1, right);  // 右を整列
    for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分
    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
    }
    i = left; j = right;
    for (k = left; k <= right; k++) {
      if (work[i] < work[j]) { array[k] = work[i++]; }
      else                   { array[k] = work[j--]; }
    }
  }
}

void main(){
    int a[SIZE];
    char x;
    set(a);
    show(a);
    printf("Sorted\n");
    merge_sort(a,0,SIZE-1);
    show(a);
}
