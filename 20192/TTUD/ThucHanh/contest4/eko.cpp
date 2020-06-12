#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

int numOfTree, *trees, hieghtest = INT32_MIN, result = INT32_MAX; 
long long woodNeed;
long long wordOfCut (int height){
    long long woodNow = 0;

    for (int i = 0; i < numOfTree; ++i){
        if (trees[i] >= height){
            woodNow += trees[i] - height;
        }
        if (woodNow >= woodNeed)
            return woodNow;
    }
    return woodNow;
}




int main(){

    cin >> numOfTree >> woodNeed;
    
    trees = new int[numOfTree];

    for(int i = 0; i < numOfTree; ++i){
        cin >> trees[i];
        hieghtest = max(trees[i], hieghtest);
    }
    int low = 0, hi = hieghtest, mid;

    while (low < hi){
        
        mid = (low + hi)/2;
        // cout << "low" << low << "mid" << mid << "hi" << hi << "     " << (wordOfCut(mid) < woodNeed) << endl;
        if(wordOfCut(mid) < woodNeed)
            hi = mid;
        else
            low = mid + 1;
        // cout << "low" << low << "mid" << mid << "hi" << hi << endl;
    }

    cout << low -1;
    

    return 0;




}
