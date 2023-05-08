#include <bits/stdc++.h>

using namespace std;

int N;
int dp[201];
int input[201];
int max_len = 1;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for(int n = 1; n <= N; n++) {
        cin >> input[n];
        dp[n] = 1;
    }
    
    for(int n = 1; n <= N; n++) {
        for(int m = 1; m < n; m++) {
            if(input[m] >= input[n]) continue;
            dp[n] = max(dp[n], dp[m] + 1);
            max_len = max(max_len, dp[n]);
        }
    }
    
    cout << N - max_len;
    
    return 0;
}
