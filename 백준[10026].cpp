#include <iostream>
#include <queue>

using namespace std;

char map[100][100];
int N, ans, ans2;
bool visited[2][100][100];

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

enum { GREEN = 'G', BLUE = 'B', RED = 'R' };

bool isAvailable(int y, int x, bool flag) {
    if(y < 0 || x < 0 || y >= N || x >= N || visited[flag][y][x]) return false;
    return true;
}

void bfs(int _y, int _x, bool flag = false) {
    visited[flag][_y][_x] = true;
    queue<pair<int, int>> q;
    
    q.push(make_pair(_y, _x));
    
    while(!q.empty()) {
        int y = q.front().first,
            x = q.front().second;
            
        q.pop();
        char now_color = map[y][x];
        
        for(int w = 0; w < 4; w++) {
            int ny = y + dy[w], nx = x + dx[w];
            
            if(!isAvailable(ny, nx, flag)) continue;
            
            if( (now_color == map[ny][nx]) ||
                (   flag &&
                    now_color != BLUE &&
                    map[ny][nx] != BLUE )) {
                visited[flag][ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            scanf(" %1c", &map[y][x]);
        }
    }
    
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if(visited[false][y][x]) continue;
            bfs(y, x);
            ans++;
        }
    }
    
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if(visited[true][y][x]) continue;
            bfs(y, x, true);
            ans2++;
        }
    }
    
    printf("%d %d", ans, ans2);
    return 0;
}
