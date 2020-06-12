#include <iostream>
#include <cmath>


using namespace std;

int main ()
{
    int a, b, c = pow(10.0, 9.0) + 7;
    cin >> a >> b; 
    long long d = 1;
    for (int i = 0; i < b; ++i){
        d = d*a;
        d = d%c;
    }
    cout << d;

}
    

    
