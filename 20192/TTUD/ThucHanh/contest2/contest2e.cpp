#include <iostream>
#include <cmath>
#include <new>

using namespace std;

int d(int * a,int u){
    if (u == 0 ) return 1;
    return (a[u] != a[u-1]);
}

int main()
{
    int n1, n2;
    cin >> n1;
    int answer = 0;
    int *a = new int[n1];
    for (int i = 0; i< n1; i++){
        cin >> a[i];
    }
    for (int i = 0; i< n1; i++){
        answer += d(a,i);
    }
    cin >> n2;
    int *q = new int[2*n2];
    for(int i =0; i <  (2 * n2); i++){
        cin >> q[i];
    }
    int index, result;
    for (int i =0; i < n2; i ++ ){
        index = q[2*i]-1; result = q[2*i +1];
        answer -= d(a, index);
        if (index != n1) answer -= d(a,index+1);
        a[index] = result; 
        answer += d(a,index);
        if (index != n1) answer += d(a,index+1);
        cout << answer << endl;
    }
    return 0;

}