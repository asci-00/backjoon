#include <iostream>
#include <queue>

using namespace std;

queue<int> _floor;
int F, G, S, U, D;
int dp[1000001];

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> F >> S >> G >> U >> D;
    
    _floor.push(S);
    dp[S] = 1;
    
    while(!_floor.empty() && dp[G] == 0) {
        int now = _floor.front(); _floor.pop();
        
        if(now - D >= 1 && !dp[now - D]) {
            _floor.push(now - D);
            dp[now - D] = dp[now] + 1;
        }
        if(now + U <= F && !dp[now + U]) {
            _floor.push(now + U);
            dp[now + U] = dp[now] + 1;
        }
    }
    
    if(dp[G]) cout << dp[G] - 1;
    else cout << "use the stairs";
    
    return 0;
}
