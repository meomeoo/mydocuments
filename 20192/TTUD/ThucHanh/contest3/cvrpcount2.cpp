#include <iostream>
#include <new>
#include <algorithm>

using namespace std;
int numOfClient, numOfTruck, capacity, *loadOfTruck, *clientRequests, *numPerTruck;
unsigned long long numOfSolution =0;


void print(int* arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
        
    }
    cout << "\n";
}
unsigned long long countGiaiThua(int i){
    unsigned long long result = 1;
    for(i; i > 0; --i){
        result *= i;
    }
    return result;
}

unsigned long long GiaiThuaTruck(){
    unsigned long long result = 1;
    for(int i = 0; i < numOfTruck; ++i){
        result = result*countGiaiThua(numPerTruck[i]);
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
        if (client >= truck){
            if((loadOfTruck[truck] + clientRequests[client]) <= capacity){
            cout << "client: " << client << " reuqest: " << clientRequests[client] << " truck: " << truck << " numPerTruck: " << numPerTruck[truck] << endl;
            loadOfTruck[truck] +=  clientRequests[client];
            numPerTruck[truck] += 1;
            if(client == (numOfClient - 1) && checkLoad() == true){
                numOfSolution += GiaiThuaTruck();
            }
            else{
                tryForClient(client + 1);
            }
                
            loadOfTruck[truck] -= clientRequests[client];
            numPerTruck[truck] -= 1;
            }
        }  
    }
}


int main(){
    cin >> numOfClient >> numOfTruck >> capacity;
    clientRequests = new int[numOfClient];
    loadOfTruck = new int[numOfTruck];
    numPerTruck = new int[numOfTruck];
    for(int i = 0; i < numOfTruck; ++i){
        loadOfTruck[i] = 0;
        numPerTruck[i] = 0;
    }
    for(int i = 0; i < numOfClient; ++i){
        cin >> clientRequests[i];
    }
    tryForClient(0);
    // numOfSolution = numOfSolution/countGiaiThua(numOfTruck - 1);
    cout <<  numOfSolution%(1000000007);


}