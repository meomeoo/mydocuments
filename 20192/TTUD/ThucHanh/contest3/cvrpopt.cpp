#include <iostream>
#include <new>
#include <algorithm>

using namespace std;
int numOfClient, numOfTruck, capacity, *loadOfTruck, *clientRequests, **distance, *numPerTruck;
bool **route;
unsigned long minOfSolution = INT64_MAX;

void print(int* arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
        
    }
    cout << "\n";
}

unsigned long calulatorCost(int* arr, int n){
    unsigned long result = 0;
    for(int i = 0; i < (n - 1); ++i){
        result += ::distance[arr[i]][arr[i + 1]];
    }
    return result;
}

unsigned long minForTruck(int* arr, int numForTruck){
    unsigned long min, result = INT64_MAX;
    do{ 
        print(arr, numForTruck + 2);
        min = calulatorCost(arr, numForTruck + 2);
        if (min < result)
            result = min;
    } while (next_permutation(arr + 1, arr + numForTruck + 1)); 
    
    return result;
}

unsigned long minForSulotion(){
    unsigned long result = 0;
    for(int i = 0; i < numOfTruck; ++i){
        int *arr = new int[numPerTruck[i] + 2];
        int t = 0;
        arr[0] = 0; arr[numPerTruck[i] + 1] = 0;
        for(int j = 0; j < numOfClient; ++j){
            if(route[i][j] == true)
                arr[++t] = j + 1;
            }
        result += minForTruck(arr,numPerTruck[i]);
        delete(arr);
    }
    return result;
}

bool checkLoad(){
    
    for(int i = 0; i < numOfTruck; ++i )
        if (loadOfTruck[i] == 0)
            return false;
    return true;
}

void tryForClient(int client){
    // cout << "n try" << "numOfClient" << numOfClient << "numOfTruck" << numOfTruck << "capacity" << capacity << endl;
    for(int truck = 0; truck < numOfTruck; ++truck){
        // cout << "client: " << client << " reuqest: " << clientRequests[client] << " truck: " << truck << " load: " << loadOfTruck[truck] << endl;
        if(client >= truck){
             if((loadOfTruck[truck] + clientRequests[client]) <= capacity){
            // cout << "client: " << client << " reuqest: " << clientRequests[client] << " truck: " << truck << " load: " << loadOfTruck[truck] << endl;
            loadOfTruck[truck] += clientRequests[client];
            route[truck][client] = true;
            numPerTruck[truck] += 1;
            if(client == (numOfClient - 1) && checkLoad() == true){
                // cout << minOfSolution << endl;

                minOfSolution = min(minOfSolution, minForSulotion());
            }
            else{
                tryForClient(client + 1);
            }
                
            loadOfTruck[truck] -= clientRequests[client];
            numPerTruck[truck] -= 1;
            route[truck][client] = false;

            }
        }
       
    }
}

int main(){
    cin >> numOfClient >> numOfTruck >> capacity;
    clientRequests = new int[numOfClient];
    loadOfTruck = new int[numOfTruck];
    numPerTruck = new int[numOfTruck];
    ::distance = new int*[numOfClient + 1];

    route = new bool*[numOfTruck];
    for(int i = 0; i < numOfTruck; ++i){
        loadOfTruck[i] = 0;
        route[i] = new bool[numOfClient];
        for(int j = 0; j < numOfClient; ++j ){
            route[i][j] = false;
        }
    }
    for(int i = 0; i < numOfClient; ++i){
        cin >> clientRequests[i];
    }
    for(int i = 0; i <= numOfClient; ++i){
        
        ::distance[i] = new int[numOfClient + 1];
        for(int j = 0; j <= numOfClient; ++j){
            cin >> ::distance[i][j];
        }
    }
    // cout << "....." << endl;
    tryForClient(0);
    cout << minOfSolution;


}