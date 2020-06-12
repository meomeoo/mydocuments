#include <iostream>
#include <vector>
#include <new>

using namespace std;
vector <int>* adj;
bool *visted;

void dfs(int node){

    if(visted[node] == true)
        return;

    visted[node] = true;

    for (auto i = adj[node].begin(); i != adj[node].end(); ++i){
        int v = *i;
        dfs(v);
    }
}

int main(){
    int numOfNode, numOfEdge, numOfConnect = 0;
    cin >> numOfNode >> numOfEdge;
    visted = new bool[numOfNode];
    for(int i = 0; i < numOfNode; ++i){
        visted[i] = false;
    }
    adj = new vector <int>[numOfNode];
    int src, des;
    for(int i = 0; i < numOfEdge; ++i ){
        cin >> src >> des;
        adj[src - 1].push_back(des - 1);
        adj[des - 1].push_back(src - 1);
    }
    for(int i = 0; i < numOfNode; ++i){
        if(visted[i] == false){
            dfs(i);
            numOfConnect++;
        }
    }

    cout << numOfConnect;
}