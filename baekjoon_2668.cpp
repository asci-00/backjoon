#include <bits/stdc++.h>

using namespace std;

int N, ans;
int second[101];
bool visited[101];
vector<int> v;

int dfs(int _now, int _size, int _origin) {
    int _next = second[_now];
    
    if(visited[_now]) return 0;
    visited[_now] = true;
    
    v.push_back(_now);
    
    if(_next == _origin) return _size;
    
    int result = dfs(_next, _size + 1, _origin);
    
    if(!result) {
        v.pop_back();
        visited[_now] = false;
    }
    
    return result;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for (int n = 1; n <= N; n++) cin >> second[n];
    
    for(int n = 1; n <= N; n++) {
        if(visited[n]) continue;
        
        if(n == second[n]) {
            v.push_back(n);
            ans ++;
        } else {
            ans += dfs(n, 1, n);
        }
    }
    
    cout << ans << '\n';
    
    sort(v.begin(), v.end());
    for(auto a : v) cout << a << '\n';
    return 0;
}
