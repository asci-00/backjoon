#include <iostream>
#include <vector>
using namespace std;

bool visited[50001], res[50001];
unsigned int N, M, a, b, ans, mid, cnt, cnt2;
vector<int> conn[50001];

bool dfs(int n) {    //dfs로 먼저 검사
    visited[n] = true;
    if(res[n]) cnt++;
        
    for(int next : conn[n]) {
        if(visited[next]) {
            if(res[next] != res[n]) continue;
            return false;
        }
        res[next] = !res[n];
        if(!dfs(next)) return false;
    }
    
    return true;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M; // N개의 수풀 M개의 오솔길
    
    for(int m = 1; m <= M; m++) {
        cin >> a >> b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    
    if(dfs(1)) {
        cnt2 = N - cnt;
        ans = N * (N - 1) - ( cnt * (cnt - 1) + cnt2 * (cnt2 - 1) );
    
    } else ans = 0;
    
    cout << ans;
    
    return 0;
}
