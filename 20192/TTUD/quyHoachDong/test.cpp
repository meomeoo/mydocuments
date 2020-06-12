#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arrar[] = {9,8,7,6,5,4,3,2,1};
    sort_heap(arrar, arrar+8);
    for (int i = 0; i < 9; i++){
        cout << arrar[i] << endl;
    }

}