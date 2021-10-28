#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iipair;

int T, N, M, ans;
vector<iipair> v;
vector<int> used, start_idx;
vector<bool> visited;

bool dfs(int now_idx) {
    auto now = v[now_idx];

    for(int idx = start_idx[now_idx] + 1; idx <= now.second; idx++) {
        if(visited[idx]) continue; visited[idx] = true;

        if(used[idx] == 0 || dfs(used[idx])) {
            used[idx] = now_idx;
            start_idx[idx] = idx;
            return true;
        }
    }
    return false;
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> M;

        v = vector<iipair>(M + 1);
        start_idx = vector<int>(M + 1);
        visited = vector<bool>(N + 1);
        used = vector<int>(N + 1);
        ans = 0;

        for(int m = 1; m <= M; m++) {
            cin >> v[m].first >> v[m].second;
            start_idx[m] = v[m].first - 1;
            if(dfs(m)) ans ++;

            fill(visited.begin(), visited.end(), false);
        }

        cout << ans << '\n';
    }

    return 0;
}