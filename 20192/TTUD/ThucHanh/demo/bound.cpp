#include <iostream>
#include <algorithm>
#include <new>

int number, Q = 0;

long long Min, Max;
using namespace std;

void cacuandCheck(int* arr,int size){
    
    long long sum = 0;
    for (int i = 0; i < size; ++i ){
        sum += (long long)(arr[i]);
    }
    if (sum >= Min && sum <= Max){
        Q +=1;
    }
    if(size < number){
        for(int i = size; i < number; ++i){
        sum = sum + (long long)(arr[i]) - (long long)(arr[i-size]);
        if (sum >= Min && sum <= Max){
            Q +=1;
        }
        }
    }


}



int main(){

    int *array;
    cin >> number >> Min >> Max;
    array = new int[number];
    for(int i = 0; i < number; ++i){
        cin >> array[i];
    }
    for(int i = 1; i <= number; ++i){
        cacuandCheck(&(array[0]), i);
    }

    cout << Q;
    return 0;
}