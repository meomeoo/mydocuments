#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

int n = 0, k = 0, serving = 0, minvalue = INT32_MAX;
int *a, *d, **c, *amax;

bool Check(int index){
    bool check = false;
    if (index <= n && serving >= 0 && serving < k){
        return true;
    }
    else if(index > n && serving > 0 && serving <= k){
        for (int i = 1; i <= n; ++i ){
            if (((d[i])*i + n) == index){
                return true;
            }
        }
        return check;
    } else 
        return false;
}

void Try(int t, int cnow){
    for (int i = 1; i <= 2*n; ++i){
        if (d[i] == 0 && Check(i) == true ){
            // cout << "first" << " t:" << t << " i:" << i << " serving:" << serving << " cnow:" << cnow << endl;
            if(i <= n){
                serving += 1;
            }else{
                d[i-n] = -1;
                serving -= 1;
            }
            d[i] = 1;
            a[t] = i;
            cnow += c[a[t-1]][a[t]];
            if(t == 2*n){
                minvalue = min(minvalue, cnow + c[a[t]][0]);
                // cout << minvalue << endl;
            }else{
                Try(t+1, cnow);
            }
            if(i <= n){
                serving -= 1;
            }else{
                d[i-n] = 1;
                serving += 1;
            }
            d[i] = 0;
            cnow -= c[a[t-1]][a[t]];
        }

    }

    return;
}

int main(){
    cin >> n >> k;
    a = new int[2*n + 1];
    d = new int[2*n + 1];
    c = new int*[2*n + 1];
    amax = new int[2*n +1];
    for (int i = 0; i <= 2*n; ++i){
        a[i] = -1;
        d[i] = 0;9/`
        c[i] = new int[2*n + 1];
        for (int j = 0; j < (2*n + 1); ++j){
            cin >> c[i][j];
        }
    }

    // int c0[] = {0, 8, 5, 1, 10, 5, 9 };
    // int c1[] = {9, 0, 5, 6, 6, 2, 8};
    // int c2[] = {2, 2, 0, 3, 8, 7, 2};
    // int c3[] = {5, 3, 4, 0, 3, 2, 7};
    // int c4[] = {9, 6, 8, 7, 0, 9, 10};
    // int c5[] = {3, 8, 10, 6, 5, 0, 2};
    // int c6[] = {3, 4, 4, 5, 2, 2, 0};
    // c[0] = &(c0[0]);
    // c[1] = &(c1[0]);
    // c[2] = &(c2[0]);
    // c[3] = &(c3[0]);
    // c[4] = &(c4[0]);
    // c[5] = &(c5[0]);
    // c[6] = &(c6[0]);

    // for (int i = 0; i < 2*n + 1; ++i){
    //     for (int j = 0; j < 2*n + 1; ++j){
    //         cout << c[i][j]  << " ";
    //     }
    //     cout << "\n" ;
    // }
    d[0] = 1;
    a[0] = 0;

    Try(1, 0);

    cout << minvalue << endl;

}
