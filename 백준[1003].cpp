#include <iostream>
using namespace std;

pair<int, int> dp[41] = {{1, 0}, {0, 1}};
int T, N;

pair<int, int> getCount(int N) {
    if(N == 0 || N == 1 || dp[N].first) return dp[N];
    
    const auto prev = getCount(N - 1), pprev = getCount(N - 2);
    
    dp[N] = make_pair(
        prev.first + pprev.first,
        prev.second + pprev.second
    );
    
    return dp[N];
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> T;
    
    while(T--) {
        cin >> N;
        const auto ans = getCount(N);
        
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
