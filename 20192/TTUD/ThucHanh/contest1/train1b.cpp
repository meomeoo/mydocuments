#include <iostream>
#include <new>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    long *max = new long[n];
    long res;
    
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    max[0] = arr[0];

    res = max[0];

    for (int i = 1; i<n; i++ ){
        if(max[i-1]>0) max[i] = arr[i]+ max[i-1];
            else max[i] = arr[i];
        if (max[i] > res) res = max[i];
    }

    cout << res;
    return 0;
    
}