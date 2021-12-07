#include <iostream>

using namespace std;

int N, M, w[101], c[101];
int dp[101][100001];

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    
    for(int n = 1; n <= N; n++) cin >> w[n] >> c[n];
    
    for(int n = 1; n <= N; n++) {
        for(int m = 1; m <= M; m++) {
            dp[n][m] = dp[n - 1][m];
            
            if(m - w[n] >= 0) dp[n][m] = max(dp[n][m], dp[n - 1][m - w[n]] + c[n]);
        }
    }
    
    cout << dp[N][M];
    
    return 0;
}
