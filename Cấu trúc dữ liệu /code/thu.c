#include<stdio.h>

int main()
{
    int b[]={1,3,2,4,4,5,6},i=0;
    int print(int* a){
        while(a[i]!=6){
        printf("a[%d]=%d\n",i+1,i);
        if (a[i]==2) return a[i];
            
        ++i;

    }
    
    }
    printf("%d",print(b));
}