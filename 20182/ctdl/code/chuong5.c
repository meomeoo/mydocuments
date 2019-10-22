#include<stdio.h>

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort (int a[], int size){
    int i,j,last;
    for(i=1;i<size,++i){
        last = a[i];
        j=i;
        while ((j>0)&&a[j-1]>last)
        {
            a[i]=a[j-1];
            j--;
        }
        a[j]=last;
    }
}

void selectionsort(int a[],n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;++j){
            if (a[j]<a[i])
                min = j;
        }
        swap(&a[i],&a[min]);
    }
}

void bubblesort(int a[],int n){
    int i,j;
    for(i=n-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if (a[j-1]>a[j]) swap(&a[j-1],&a[j]);
        }
    }
}