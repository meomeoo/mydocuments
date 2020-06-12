#include <iostream>
#include <algorithm>
#include <new>
#include <math.h>

using namespace std;


int count(int* position, int n, int mid, int numOfCow){
    int point = position[0], count = 1;
    for(int i = 1; i < n; ++i){
        if((position[i] - point) >= mid){
            point = position[i];
            ++count;
            if(count >= numOfCow)
                return count;
        } 

    }
    return count;
}

void test(){
    int numOfStall, numOfCow;
    cin >> numOfStall >> numOfCow;
    int *position = new int[numOfStall];
    for(int i = 0 ; i < numOfStall; ++i){
        cin >> position[i];
    }
    sort(position, position + numOfStall);
    long long low = 1, high = position[numOfStall - 1], mid;

    while(high > low){
        mid = (high + low)/2;
        if(count(position, numOfStall, mid, numOfCow) < numOfCow)
            high = mid;
        else
            low = mid + 1;   
    }
    
    // for(int i = 0; i < numOfStall; ++i){
    //     cout << position[i] << " ";
    // }
    // cout << "\n";
    cout << low  - 1 << endl;
    // cout << count(position, numOfStall, 3) << endl;

}

int numOfTest;
int main(){
    cin >> numOfTest;
    for(int i = 0; i < numOfTest; ++i){
        test();
    }

}