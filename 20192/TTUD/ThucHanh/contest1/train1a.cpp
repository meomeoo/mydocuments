#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    unsigned long long a,b,a0,b0,a1,b1,c0,c1;
    cin >> a >> b;
    a0 = a/10; b0 = b/10;
    a1 = a%10; b1 = b%10;
    c0 = a0 + b0 + (a1+b1)/10;
    c1 = (a1 + b1)% 10;
    if (c0 > 0) cout << c0;
    cout << c1;
    return 0;

}