#include <iostream>
#include <queue>

using namespace std;

bool map[100][100];
int N, M, cheese, ans;
const int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};


bool isPossible(int y, int x) { return !(y < 0 || x < 0 || y >= N || x >= M); }

void bfs(int y, int x, bool (*visited)[100], int (*adjCnt)[100]) {
    queue<pair<int, int>> pos, adjEmpty;
    bool inner = true, flag;
    
    visited[y][x] = true;
    pos.push(make_pair(y, x));
    
    
    while(!pos.empty()) {
        auto nowPos = pos.front(); pos.pop();
        int nowY = nowPos.first, nowX = nowPos.second;
        
        flag = true;
        
        for(int w = 0; w < 4; w++) {
            int nxtY = nowY + dy[w], nxtX = nowX + dx[w];
            
            if(!isPossible(nxtY, nxtX)) inner = false;      //벽에 닿은 빈공간일 경우
            else if(!visited[nxtY][nxtX]) {                 //방문하지 않은 경우
                if(map[nxtY][nxtX]) {                       //치즈일 경우
                    adjCnt[nxtY][nxtX]++;
                    if(flag) {
                        adjEmpty.push(make_pair(nowY, nowX));
                        flag = false;
                    }
                    continue;
                }
                
                visited[nxtY][nxtX] = true;
                pos.push(make_pair(nxtY, nxtX));
            }
        }
    }
    
    
    if(inner) {
        while(!adjEmpty.empty()) {
            auto nowPos = adjEmpty.front(); adjEmpty.pop();
            int nowY = nowPos.first, nowX = nowPos.second;
            
            for(int w = 0; w < 4; w++) {
                int nxtY = nowY + dy[w], nxtX = nowX + dx[w];
                
                if(!isPossible(nxtY, nxtX)) continue;
                if(map[nxtY][nxtX]) adjCnt[nxtY][nxtX] --;
            }
        }
    }
}

void progress() {
    bool visited[100][100] = {false, };
    int adjCnt[100][100] = {0,};
    
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(visited[y][x] || map[y][x]) continue;
            bfs(y, x, visited, adjCnt);
        }
    }
    
    for(int y = 0; y < N; y++) for(int x = 0; x < M; x++) if(adjCnt[y][x] >= 2) { map[y][x] = false; cheese --; }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            cin >> map[y][x];
            if(map[y][x]) cheese ++;
        }
    }
    
    while(cheese) { progress(); ans++; }
    
    cout << ans;
    return 0;
}
