#include <bits/stdc++.h>

using namespace std;
/*
    N - 노드개수 / v - 간선개수 / conn - 연결정보 / nxt - 다음에 체크할 노드
    aflag - 오일러회로 존재 여부
    1시간 안에 못품..
    참고url : https://www.acmicpc.net/board/view/72338
*/
int N, v, conn[1011][1011], nxt[1011];
bool aflag = true;

void dfs(int now) {
    for(int& next = nxt[now]; next <= N; next++) {
        while(conn[now][next]) {
            conn[next][now] = (--conn[now][next]);
            dfs(next);
        }
    }
    cout << now << ' ';
}
int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int f = 1; f <= N; f++) {
        nxt[f] = 1;
        for(int t = 1; t <= N; t++) {
            cin >> conn[f][t];
            v += conn[f][t];
        }
        if(v % 2 != 0) { aflag = false; break; }
    }
    if(!aflag) { cout << -1; }
    else dfs(1);

    return 0;
}