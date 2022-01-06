#include <iostream>
#include <queue>

using namespace std;

struct node {
    int c, r, d;
    node(int col, int row, int dist) : c(col), r(row), d(dist) {}
    bool operator < (const node& p)const {
        if(d == p.d) {
            if(c == p.c) return r > p.r;
            return c > p.c;
        }
        return d > p.d;
    }
};

int _size, dc[] = {-1, 0, 0, 1}, dr[] = {0, -1, 1, 0}, map[20][20], col, row, N, res, ans, need;

bool isPossible(int c, int r) { return ( c >= 0 && r >= 0 && c < N && r < N && _size >= map[c][r] ); }

int bfs() {
    priority_queue<node> pos;
    bool visited[20][20] = {false,};
    
    visited[col][row] = true;
    
    pos.push(node(col, row, 0));
    
    while(!pos.empty()) {
        auto now = pos.top(); pos.pop();
        
        if(map[now.c][now.r] && map[now.c][now.r] < _size) {
            map[now.c][now.r] = 0;
            col = now.c; row = now.r;
            if(--need == 0) need = ++_size;

            return now.d;
        }
        
        for(int w = 0; w < 4; w++) {
            int nxtC = now.c + dc[w], nxtR = now.r + dr[w];
            if(!isPossible(nxtC, nxtR) || visited[nxtC][nxtR]) continue;
            
            visited[nxtC][nxtR] = true;
            pos.push(node(nxtC, nxtR, now.d + 1));
        }
    }
    
    return 0;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int c = 0; c < N; c++) {
        for(int r = 0; r < N; r++) {
            cin >> map[c][r];
            if(map[c][r] == 9) { col = c; row = r; map[c][r] = 0; }
        }
    }
    
    _size = need = 2;
    
    while(res = bfs()) ans += res;
    
    cout << ans;
    return 0;
}
