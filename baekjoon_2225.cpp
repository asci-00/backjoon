#include <iostream>
#define MAX 1000000000

using namespace std;

int N, K, dp[201][201];

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    
    for(int n = 0; n <= N; n++) dp[1][n] = 1;
    
    for(int k = 2; k <= K; k++) { // 사용 횟수
        for(int n = 0; n <= N; n++) {
            for(int prev = 0; prev <= (N - n); prev ++) {
                if(!dp[k - 1][prev]) continue;
                
                dp[k][prev + n] = ( dp[k][prev + n] + dp[k - 1][prev] ) % MAX;
            }
        }
    }
    
    cout << dp[K][N];
    return 0;
}
