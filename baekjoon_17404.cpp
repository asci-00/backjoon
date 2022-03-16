#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[3][1001][3], temp[3];

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for(int i = 0; i < 3; i++) {
        cin >> dp[i][0][i];
        for(int root = 0; root < 3; root++) {
            if(i == root) continue;
            dp[i][0][root] = 9999;
        }
    }
    
    
    for(int n = 1; n < N; n++) {
        for(int i = 0; i < 3; i++) {
            cin >> temp[i];
            
            for(int root = 0; root < 3; root++) dp[root][n][i] = temp[i];
        }
        
        if(n == 1) for(int root = 0; root < 3; root++) dp[root][n][root] = 99999;
        
        for(int root = 0; root < 3; root++) {
            dp[root][n][0] += min(dp[root][n - 1][1], dp[root][n - 1][2]);
            dp[root][n][1] += min(dp[root][n - 1][0], dp[root][n - 1][2]);
            dp[root][n][2] += min(dp[root][n - 1][0], dp[root][n - 1][1]);
        }
    }
    
    const int ans = min({
        dp[0][N - 1][1], dp[0][N - 1][2],
        dp[1][N - 1][0], dp[1][N - 1][2],
        dp[2][N - 1][0], dp[2][N - 1][1] 
    });
    
    cout << ans;
    
    return 0;
}
