#include <iostream>
#include <cstring>

#define MAX 16
#define INF (1000000 * MAX + 1)

using namespace std;
// 틀린 풀이 - 최소신장트리 문제로 착각..
// class ConnectInfo {
// public:
//     int cost, st, ex;
//     ConnectInfo(int c, int s, int e) : cost(c), st(s), ex(e) {}
//     bool operator < (const ConnectInfo& p) const { return cost > p.cost; }
// };

// int N, I, parent[MAX + 1], line, ans;  //노드 개수 1~N

// priority_queue<ConnectInfo> conn;

// int Find(int node) {
//     if(node == parent[node]) return node;
//     return parent[node] = Find(parent[node]);
// }

// void Union(int a, int b) {
//     int pa = Find(a), pb = Find(b); //a의 최상위 부모노드 pa, b의 최상위 부모 노드 pb
//     parent[pa] = pb;    //pa의 부모를 pb로 합치기
// }

// int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     cin >> N;
//     for(int y = 1; y <= N; y++) {
//         parent[y] = y;
//         for(int x = 1; x <= N; x++) {
//             cin >> I;
//             conn.push(ConnectInfo(I ? I : INF, y, x)); //I값이 0이면 무한
//         }
//     } line = N - 1;

//     while(conn.size() && line) {
//         auto now = conn.top(); conn.pop();
//         if(Find(now.st) == Find(now.ex)) continue;

//         Union(now.st, now.ex);
//         ans += now.cost;
//         line--; //연결
//     }

//     cout << ans;
//     return 0;
// }


int dp[1 << MAX][MAX];    // index 1 : 연결된 노드들 / index 2 : 마지막 연결된 노드
int cost[MAX][MAX], N;

int dfs(int conn_nodes, int now) {

    if(conn_nodes == ((1 << N) - 1)) return (cost[now][0] ? cost[now][0] : INF);    //모든 노드 연결
    if(!dp[conn_nodes][now]) {
        dp[conn_nodes][now] = INF;
        for(int nxt = 0; nxt < N; nxt++) {
            if(!cost[now][nxt] || (conn_nodes & (1 << nxt))) continue;
            dp[conn_nodes][now] = min(dp[conn_nodes][now], cost[now][nxt] + dfs(conn_nodes | (1 << nxt), nxt));
        }
    }
    return dp[conn_nodes][now];
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int f = 0; f < N; f++) for(int t = 0; t < N; t++) cin >> cost[f][t];

    cout << dfs(1, 0);
    return 0;
}