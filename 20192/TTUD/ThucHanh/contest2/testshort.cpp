#include <iostream>

using namespace std;

    void ksort( int * a, int n){
        int j;
        int temp;
        for (int i = 1; i < n; ++i){
            j = i -1;

            for(j; j >= 0; --j){
                if (a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }

            }

        }
    }

}