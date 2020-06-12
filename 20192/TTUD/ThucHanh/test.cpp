#include <iostream>
#include <algorithm>

using namespace std;
void print(int* arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
        
    }
    cout << "\n";
}

int main()
{
    int arr[] = {0, 4, 5, 6, 0};
    sort_heap(arr, arr + 5);
    print(arr, 5);
}