#include <iostream>
#include <queue>

using namespace std;

int N, M, hour, piece, cheese;
const int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
bool map[101][101], visited[101][101], now;
queue<pair<int, int>> pos[2];

bool isPossible(int y, int x) {
    if( y < 1 || x < 1 || y > N || x > M || visited[y][x] ) return false;
    return true;
}

bool bfs() {
    int x, y, nx, ny;
    
    if(cheese == 0) return true;
    
    now = !now;
    hour ++;
    
    while(!pos[now].empty()) {
        auto now_pos = pos[now].front(); pos[now].pop();
        y = now_pos.first; x = now_pos.second;
        map[y][x] = 0;
        
        for(int w = 0; w < 4; w++) {
            ny = y + dy[w]; nx = x + dx[w];
            if(!isPossible(ny, nx)) continue;
            else if(map[ny][nx]) {
                pos[!now].push(make_pair(ny, nx));
                cheese--;
            } else pos[now].push(make_pair(ny, nx));
            
            visited[ny][nx] = true;
        }
    }
    return false;
}

void checkPiece(int y, int x) {
    int ny, nx;
    
    visited[y][x] = true;
    for(int w = 0; w < 4; w++) {
        ny = y + dy[w]; nx = x + dx[w];
        if(!isPossible(ny, nx) || !map[y][x]) continue;
        checkPiece(ny, nx);
    }
}

void countPiece() {
    int x, y;
    
    while(!pos[!now].empty()) {
        auto now_pos = pos[!now].front(); pos[!now].pop();
        y = now_pos.first; x = now_pos.second;
        
        visited[y][x] = false;
        pos[now].push(make_pair(y, x));
    }
    while(!pos[now].empty()) {
        auto now_pos = pos[now].front(); pos[now].pop();
        checkPiece(now_pos.first, now_pos.second);
        piece++;
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int n = 1; n <= N; n++) {
        for(int m = 1; m <= M; m++) {
            cin >> map[n][m];
            if (map[n][m]) cheese++;
            else if ( n == 1 || m == 1 || n == N || m == M ) {
                pos[!now].push(make_pair(n, m));
                visited[n][m] = true;
            }
        }
    }
    
    while(!bfs());
    countPiece();
    
    cout << hour << '\n' << piece;
    return 0;
}
