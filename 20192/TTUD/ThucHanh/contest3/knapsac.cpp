#include <iostream>
#include <new>

using namespace std;


void Try(int k, int mnow, long long cnow, int n, int b,  int *d, int *m, int *c, long long *max)
{
    for (int i = 0; i < n; ++i){
        if((d[i]) == 0){
            d[i] = 1;
            cnow += (long long)c[i];
            mnow += m[i];
            if(k == (n-1) && mnow <= b){
                if (cnow > *max)
                    *max = cnow;
            } else if ( mnow > b || k == (n-1)){}
            else{
                if (cnow > (*max))
                    *max = cnow;
                Try(k+1, mnow, cnow, n, b, &(d[0]), &(m[0]), &(c[0]), &(*max));
            }
            cnow -= (long long)c[i];
            mnow -= m[i];
            d[i] = 0;
        }
    }
    return;
}


int main(){
    int b, *d, *c, *m, n;
    long long max = 0;
    cin >> n >> b;
    d = new int[n];
    c = new int[n];
    m = new int[n];

    for (int i = 0; i < n; ++i){
        d[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        cin >> m[i];
        cin >> c[i];
    }

    Try(0, 0, 0, n, b, &(d[0]), &(m[0]), &(c[0]), &max);

    cout << max ;

    return 0;

}