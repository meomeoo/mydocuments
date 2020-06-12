#include <iostream>
#include <algorithm>
#include <new>
#include <math.h>
#include <stdio.h>

using namespace std;

int numOfTest;
double *result, pi = 3.1415926535897932384626;

void testCase(int test_th)
{
    int numOfPie, numOfFriends;
    cin >> numOfPie >> numOfFriends;
    double *v = new double[numOfPie];
    double r, hi = 4e8, low = 0, mid;
    for (int i = 0; i < numOfPie; ++i)
    {
        cin >> r;
        v[i] = pi * r * r;
    }
    sort_heap(v, v + numOfPie);
    for( int it = 0; it < 100; it ++)
    {
        mid = (low + hi) / 2;
        int cont = 0;
        for (int i = numOfPie - 1; i >= 0 && cont <= numOfFriends; --i){
            cont += (int)floor(v[i]/ mid);
        }
            

        if (cont > numOfFriends)
            low = mid;
        else
            hi = mid;

    }
    result[test_th] = low;
    return;

}

int main()
{
    cin >> numOfTest;
    result = new double[numOfTest];
    for (int i = 0; i < numOfTest; ++i){
        testCase(i);
    }
    for (int i = 0; i < numOfTest; ++i){
        printf ( "%0.6f\n" , result[i] );
    }
    return 0;
}
    