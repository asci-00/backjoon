#include <iostream>
#define _MAX 1000000000

using namespace std;

int dp[105][10][1 << 10], ans;
int N;

int dfs(int idx, int num, int bit) {
    if(dp[idx][num][bit]) return dp[idx][num][bit];
    if(idx == N) return bit == (1 << 10) - 1;
    
    int cnt = 0;
    
    cnt += (num + 1 < 10) ? dfs(idx + 1, num + 1, bit | 1 << (num + 1)) : 0;
    cnt += (num - 1 >= 0) ? dfs(idx + 1, num - 1, bit | 1 << (num - 1)) : 0;
    
    return (dp[idx][num][bit] = (cnt %= _MAX));
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for(int s = 1; s < 10; s++) {
        ans += dfs(1, s, 1 << s);
        ans %= _MAX;
    }
    
    cout << ans;
    return 0;
}
