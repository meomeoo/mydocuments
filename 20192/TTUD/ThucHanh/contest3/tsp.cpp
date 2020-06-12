#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

void Try (int k, int n, int chiphi, int* minvalue, int* check, int* lotrinh, int **c ){
    
    for(int i = 0; i < n; ++i){
        if (c[lotrinh[k-1]][i] != 0 && check[i] == 0){
            lotrinh[k] = i;
            chiphi += c[lotrinh[k-1]][i];
            check[i] = 1;
            if (k == (n-1)){
                if(c[lotrinh[k]][0] != 0){
                    *minvalue = min((*minvalue), (chiphi + c[lotrinh[k]][0])); 
                }
            }else {
                Try(k + 1, n, chiphi, &(*minvalue), &(check[0]), &(lotrinh[0]), c);
            }
            chiphi -= c[lotrinh[k-1]][i];
            check[i] = 0;
        } 
    }
    return;

}

int main(){
    int n, m, row, colum, value, minvalue = INT32_MAX;
    cin >> n >> m;
    int *lotrinh = new int[n];
    int *check = new int[n];
    int **c = new int*[n];
    for (int i = 0; i < n; ++i){
        lotrinh[i] = -1;
        check[i] = 0;
        c[i] = new int[n];
        for (int j = 0; j < n; ++j){
            c[i][j] = 0;
        }
    }
    check[0] = 1;
    lotrinh[0] = 0;

    for (int i = 0; i < m; ++i){
        cin >> row >> colum >> value;
        c[row -1][colum -1] = value;
    }

    Try(1, n, 0, &minvalue, &(check[0]), &(lotrinh[0]), c);

    cout << minvalue;

    return 0;

}