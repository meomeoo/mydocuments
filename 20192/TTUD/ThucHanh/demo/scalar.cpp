#include <iostream>
#include <new>
#include <algorithm>

using namespace std;

long long cacu(int *array, int size)
{

    long long sum = 0;
    long long tic;
    for (int i = 0; i < size; ++i)
    {
        tic = (long long)(array[i]) * (long long)(array[size*2 - 1 -i]);
        sum += tic;
    }
    return sum;
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

int main()
{
    long long *minPerTest;
    int ntest, **test, *numOfTest;
    cin >> ntest;
    numOfTest = new int[ntest];
    minPerTest = new long long[ntest];
    test = new int *[ntest];
    for (int i = 0; i < ntest; ++i)
    {
        cin >> numOfTest[i];
        test[i] = new int[numOfTest[i] * 2];
        for (int j = 0; j < (2 * numOfTest[i]); ++j)
        {
            cin >> test[i][j];
        }
    }
    int *arr1, *arr2;

    for (int i = 0; i < ntest; ++i){
        arr1 = &(test[i][0]);
        arr2 = &(test[i][numOfTest[i]]);
        heapSort(arr1, numOfTest[i]); 
        heapSort(arr2, numOfTest[i]);
         
    }


    for (int i = 0; i < ntest; ++i)
    {
        long long minNow = INT64_MAX; 
        long long result;
        result = cacu(&(test[i][0]), numOfTest[i]);
        minNow = min(minNow, result);
        minPerTest[i] = minNow;
    }

    for (int i = 0; i < ntest; ++i){

        cout << "Case #" << (i+1) << ": " << minPerTest[i] << endl;
    }
    return 0;
}