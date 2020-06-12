#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, b, ansthunglung = 0, ansdoi = 0;
    long long maxthunglung = 0;
    long long maxdoi = 0;
    cin >> n >> b;
    int *arr = new int[n];
    for(int i =0; i < n ; i++){
        cin >> arr[i];
    }
    int *pre = new int[n];
    int *predoi = new int[n];
    pre[0] = arr[0];
    predoi[0] = arr[0];
    int *suf = new int[n];
    int *sufdoi = new int[n];
    suf[n-1] = arr[n-1];
    sufdoi[n-1] = arr[n-1];
    for(int i =1; i<n; i++){
        if(arr[i]> pre[i-1])
            pre[i] = arr[i];
        else pre[i] = pre[i-1];
        if(arr[i]< predoi[i-1])
            predoi[i] = arr[i];
        else predoi[i] = predoi[i-1];
    }
    for(int i = n-2; i >= 0; i--){
        if(arr[i]> suf[i+1])
            suf[i] = arr[i];
        else suf[i] = suf[i+1];
        if(arr[i]< sufdoi[i+1])
            sufdoi[i] = arr[i];
        else sufdoi[i] = sufdoi[i+1];
    }
    for(int i = 1; i < (n -1) ; i++){
        if(((pre[i-1]- arr[i])>= b) && ((suf[i+1]-arr[i])>= b))
            maxthunglung = max((long long )(pre[i-1]- arr[i]), (long long)(suf[i+1]- arr[i]));

            if (maxthunglung >= ansthunglung) ansthunglung = d;
        if(((pre[i-1]- arr[i])>= b) && ((suf[i+1]-arr[i])>= b))
            maxthunglung = max((long long )(pre[i-1]- arr[i]), (long long)(suf[i+1]- arr[i]));

            if (maxthunglung >= ansthunglung) ansthunglung = d;
    }
    delete arr;
    delete suf;
    delete pre;
    cout << ansthunglung << endl;
    return 0;



}