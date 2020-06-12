#include <iostream>
#include <new>
#include <algorithm>

using namespace std;
int main(){

    int numOfMachine;
    cin >> numOfMachine;
    long long result = -1;
    if(numOfMachine >= 2 && numOfMachine <= 2000000){
    int* start, *end;
    long long *maxValue;

    start = new int[numOfMachine];
    end = new int[numOfMachine];
    maxValue = new long long[numOfMachine];
    for(int i = numOfMachine - 1; i >= 0 ; --i){
        cin >> start[i] >> end[i];
        maxValue[i] = 0;
    }

    maxValue[0] = (long long)(end[0] - start[0]);
    for(int i = 1; i < numOfMachine; ++i){
        maxValue[i] = max(maxValue[i - 1], (long long)(end[i] - start[i]));
    }

    for(int i = 1; i < numOfMachine; ++i ){
        for(int j = i - 1; j >= 0; --j){
            if(end[j] < start[i]){
                result = max(result, (long long)(end[i] - start[i] + maxValue[j]));
                break;
            }
        }
    }
    }
    
    cout << result << endl;
    return 0;



}