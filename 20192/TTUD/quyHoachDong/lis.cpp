#include <iostream>
#include <algorithm>
#include <new>

using namespace std;
int array[10], maxArry[10], result = INT32_MIN;

int lis(int i){
    if (maxArry[i] != -1)
        return maxArry[i];

    int res= 1;
    for (int j = 0; j < i; ++j){
        if(array[j] < array[i])
            res = max(res, 1 + lis(j));
    }

    maxArry[i] = res;
    result = max(maxArry[i], result);
    return res;
}

int main(){


    for (int i = 0; i < 10; ++i){
        cin >> array[i];
        maxArry[i] = -1;
    }

    lis(9);
    cout << result << endl;

}