#include <iostream>

using namespace std;
long long add (int* arr, int i){
    long long max = (long long)arr[i];
    long long max1 = max;
    int min = arr[i]; 
    int n= 1;
    while(true){
        if ((arr[i-n] == 0) || ((i-n) < 0))  return max;
;
        if (arr[i-n]<min) min = arr[i-n];
        max1 = (long long)min*(n+1);
        if (max1>max) max = max1;
        n++;
    }
}
    


int main()
{
    long long res[10000] ;
    int n =0;
    int z = 0;
    while(true)
    {
        cin >> n;
        if ( n == 0 ) break;
        int *arr = new int[n];
        for (int i = 0; i< n; i++)
        {
            cin >> arr[i];
        }
        long long max = arr[0];
        long long s = max;

        for(int i =1; i<n; i++ )
        {
            if(arr[i]> 0) 
                max = add(arr, i);
            if (max> s) 
                s = max ;
        }
        res[z] = s;

        z++;
    }
    for (int i = 0; i < z;i ++ ){
        cout << res[i] << endl; 
    }
    return 0;
}