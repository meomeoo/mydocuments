#include <iostream> 
#include <cmath>
#include <new> 

using namespace std;

int main()
{
    int n;
    long long b = 0, c = pow(10, 9)+ 7;
    cin >> n;
    int* arr  = new int[n];

    for  (int i = 0; i < n; i++){
        cin >> arr[i];
        b += (long long)arr[i];
    }    
    cout << b%c;
    return 0;

}