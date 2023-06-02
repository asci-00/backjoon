#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,m;

int field[300][300] = { 0 };
int wx[] = {-1, 1, 0, 0};
int wy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void melt() {
    bool visited[300][300] = {false};
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(!field[y][x]) continue;
            
            for(int w = 0; w < 4; w++) { // 상하좌우에 물 있는지
                int nx = x + wx[w];
                int ny = y + wy[w];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || field[ny][nx] || visited[ny][nx]) continue;
                field[y][x] = (field[y][x] - 1 < 0) ? 0 : field[y][x] - 1; // 물 있으면 감소
            }
            visited[y][x] = true;
            if(field[y][x]) q.push(make_pair(y, x));
        }
    }
}

void dfs(int y, int x, bool visited[300][300]) {
    for(int w = 0; w < 4; w++) {
        int nx = wx[w] + x;
        int ny = wy[w] + y;
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || !field[ny][nx]) continue;
        visited[ny][nx] = true;
        dfs(ny, nx, visited);
    }
}

int reamin_ice() {
    int cnt = 0;
    
    bool visited[300][300] = {false};
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        
        if(visited[y][x]) continue;
        
        visited[y][x] = true;
        dfs(y, x, visited);
        cnt ++;
    }
    
    return cnt;
}

int main() {
    cout.tie(0); cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
            if(field[i][j]) q.push(make_pair(i, j));
        }
    }
    
    for(int y = 0;; y++) {
        int num = reamin_ice();
        melt();
        
        if(num > 0 && num < 2) continue;
        
        if(num >= 2) cout << y;
        else if(!num) cout << 0;
        break;
    }
    return 0;
}
