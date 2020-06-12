#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

int main(){
    int W, H, number;
    cin >> W >> H >> number;
    int *w, *h;
    w = new int[number];
    h = new int[number];

    for(int i = 0; i < number; ++i){
        cin >> w[i] >> h[i];
    }
    int **dp = new int*[W + 1];
    for(int i = 0; i <= W; ++i){
        dp[i] = new int[H + 1];
        for(int j = 0; j <= H; ++j){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= W; ++i){
        for(int j = 1; j <= H; ++j){
            dp[i][j] = i*j;
            for(int k = 0; k < number; ++k){
                if(w[k] == i && h[k] == j){
                    dp[i][j] = 0;
                    break;
                }
            }
            for(int k = 1; k <= i; ++k){
                dp[i][j] = min(dp[k][j] + dp[i - k][j], dp[i][j]);
            }

            for(int k = 1; k <= j; ++k){
                dp[i][j] = min (dp[i][k] + dp[i][j - k], dp[i][j]);
            }
        }
    }

    cout << dp[W][H];

    return 0;

}