#include <iostream>

using namespace std;
int dp[1000001] = {0, 0, 1, 1, }, _prev[1000001] = {0, 0, 1, 1}, N, prev_idx;

int main() {
    cin >> N;
    for(int n = 4; n <= N; n++) {
        int two = 1000001, three = 1000001;
        dp[n] = 1000001;
        
        if(n % 3 == 0) {
            three = dp[n / 3] + 1;
            prev_idx = n / 3;
            
            dp[n] = three;
        }
        
        if(n % 2 == 0) {
            two = dp[n / 2] + 1;
            if(two < dp[n]) {
                prev_idx = n / 2;
                dp[n] = two;
            }
        }
        
        int one = dp[n - 1] + 1;
        
        if(one < dp[n]) {
            prev_idx = n - 1;
            dp[n] = one;
        }
        
        _prev[n] = prev_idx;
    }
    cout << dp[N] << '\n';
    
    int now = N;
    
    while(now) {
        cout << now << ' ';
        now = _prev[now];
    }
    return 0;
}
