#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> T;
    
    while(T--) {
        cin >> N;
        
        int val[500][500] = {0, };
        int dp[500][500] = {0, };
        
        for(int n = 0; n < N; n++) {
            cin >> val[n][n];
        }
        
        for(int e = 0; e < N; e++) {
            for(int s = e - 1; s >= 0; s--) {
                val[s][e] = val[s][e - 1] + val[e][e];
                
                for(int r = 1; r <= e - s; r++) {
                    int _next = dp[s][e - r] + val[s][e - r] + dp[e - r + 1][e] + val[e - r + 1][e];
                    
                    dp[s][e] = dp[s][e] ? min(dp[s][e], _next) : _next;
                }
            }
        }
        
        cout << dp[0][N - 1] << '\n';
    }
    
    return 0;
}
