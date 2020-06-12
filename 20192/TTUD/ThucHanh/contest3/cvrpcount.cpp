#include <iostream>
#include <new>

using namespace std;

int numOfClient, numOfTruck, capacity, *requests, *loadOfTruck;
long long nSolution = 0, c = 1000000007;
bool **routes;

    

void Try(int request){
    for (int truck = 0; truck < numOfTruck; ++truck){
        if((loadOfTruck[truck] + requests[request]) <= capacity){
            cout <<  "request: " <<request <<  "  truck: " << truck  << endl;
            for (int i = 0; i < numOfTruck; ++i){
                for (int j = 0; j < numOfClient; ++j ){
                    cout << routes[i][j] << ' ';
                }
                cout << "\n";
            }
            loadOfTruck[truck] += requests[request];    
            routes[truck][request] = 1;
            cout << "\n";
            for (int i = 0; i < numOfTruck; ++i){
                for (int j = 0; j < numOfClient; ++j ){
                    cout << routes[i][j] << ' ';
                }
                cout << "\n";
            }
            if(request == (numOfClient - 1)){
                nSolution += 1;
                if(nSolution == c)
                    nSolution -= c;
        
            }else{
                Try(request + 1);
            }

            loadOfTruck[truck] -= requests[request];
            routes[truck][request] = 0;
        }

    }
}


int main(){


    cin >> numOfClient >> numOfTruck >> capacity;

    routes = new bool*[numOfTruck];
    requests = new int[numOfClient];
    loadOfTruck = new int[numOfTruck];
    for (int i = 0; i < numOfTruck; ++i){
        loadOfTruck[i] = 0;
        routes[i] = new bool[numOfClient];
        for (int j = 0; j < numOfClient; ++j ){
            routes[i][j] = 0;
        }
    }

    for(int i = 0; i < numOfClient; ++i){
        cin >> requests[i];
    }
Try(0);

    cout << (nSolution%c);
}