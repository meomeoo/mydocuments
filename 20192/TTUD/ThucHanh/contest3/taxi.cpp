#include <algorithm>
#include <iostream>
#include <new>

using namespace std;

int calulatorCost(int **input,int *arr, int n){

    int cost = 0;

    for (int i = 0; i < n - 1; ++i){
        cost += input[arr[i]][arr[i] + n] + input[arr[i] + n][arr[i+1]];
    }

    cost += input[arr[n-1]][arr[n-1] + n] + input[0][arr[0]] + input[arr[n-1] + n][0];
    
    return cost;
}

int main(){

    int n, result = INT32_MAX, min = 0;
    cin >> n;

    int **input = new int*[2*n + 1];
    for (int i = 0; i < (2*n +1); ++i){
        input[i] = new int[2*n +1 ];
        for(int j = 0; j < (2*n + 1); ++j){
            cin >> input[i][j];
        }
    }

    int *arr = new int[n];
    for (int i = 0; i < n; ++i){
        arr[i] = i + 1;
    }

    do{     
        min = calulatorCost(input, arr, n);
        if (min < result)
            result = min;
    } while (next_permutation(arr, arr + n)); 

    cout << result;
    return 0;
}