#include <iostream>
#include <new>
#include <algorithm>

using namespace std;

int main(){

    int result = -1;
    int nunmOfSolution, timeLimit, D;
    cin >> nunmOfSolution >> timeLimit >> D;
    int **dp = new int*[nunmOfSolution];
    int *amountOfGoods = new int[nunmOfSolution];
    int *timeTakingGoods = new int[nunmOfSolution];

    for(int i = 0; i < nunmOfSolution; ++i){
        cin >> amountOfGoods[i];
        dp[i] = new int[timeLimit + 1];
        for(int j = 0; j <= timeLimit; ++j){
            // if (j < timeTakingGoods[i])
                dp[i][j] = 0;
        }
    }
      for(int i = 0; i < nunmOfSolution; ++i){
        cin >> timeTakingGoods[i];
        
    }
    for(int i = 0;i <= timeLimit ;++ i){
        if(i < timeTakingGoods[0]){
            dp[0][i] = 0;
        }else{
            dp[0][i] = amountOfGoods[0];
        }

    }

    for(int i = 1 ; i < nunmOfSolution; ++i){
        for (int k = timeTakingGoods[i]; k <= timeLimit; ++k){
            for (int j = i - 1; j >= max(0, i - D); --j){
                dp[i][k] = max(dp[i][k], dp[j][k - timeTakingGoods[i]] + amountOfGoods[i]);
            }
            result = max(dp[i][k], result);
            // cout << "dp[" << i << "]" << "[" << k << "]: "<< dp[i][k] << " " << " result: " << result << endl; 
        }
    }
    cout << result;

}