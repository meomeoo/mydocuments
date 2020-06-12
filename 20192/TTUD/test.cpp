#include <iostream>
#include <new>
using namespace std;

int main()
{
    int *a = new int[10];
    int *b = new int[10];

    int *c = new int[10];

    for (int i = 0; i < 10 ; ++i){
        cout << a[i] << b[i] << c[i] ;
    } 
    return 0;
}