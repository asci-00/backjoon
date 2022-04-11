#include <iostream>
#include <vector>

using namespace std;

int N, I, _max;
int dp[1000001], pos[1000001];

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int n = 1; n <= N; n++) {
        cin >> I;
        
        dp[n] = 1;
        pos[I] = n;
    }
    
    _max = 1;
    dp[1] = 1;
    
    for(int n = 2;  n <= N; n++) {
        if (pos[n] < pos[n - 1]) dp[n] = 1;
        else {
            dp[n] = dp[n - 1] + 1;
            _max = max(_max, dp[n]);
        }
    }
    
    cout << N - _max;
    return 0;
}
