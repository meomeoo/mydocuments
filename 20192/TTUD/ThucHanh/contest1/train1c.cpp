#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    
    long long a,b,a0, b0,  c= pow(10.0, 9.0) + 7, c0;
    cin >> a >> b;
    a0 = a/c ; b0 = b/c;
    
    a = a - a0*c; b = b -b0*c;
    c0 = a +b;
    if (c0 < c) cout << c0;
        else cout << ((a+b)%c);
    return 0;
    

    
}