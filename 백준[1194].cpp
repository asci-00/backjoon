#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

#define MAX 50
using namespace std;

int N, M, sx, sy;
char map[MAX + 2][MAX + 2];
const int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
bool visited[(1 << 6)][MAX + 2][MAX + 2];

class info {
public:
    info(int _y, int _x, int _set, int _cnt=0) : y(_y), x(_x), key_set(_set), cnt(_cnt) {}
    int y, x, key_set, cnt;
};

queue<info> q;

enum { FAIL = -3, EXIT };

int getType(int y, int x, int key_set) {
    char now = map[y][x];
    if( now == 0 || now == '#' || visited[key_set][y][x] ||
        (now >= 'A' && now <= 'F') && !(key_set & (1 << now - 'A'))) return FAIL;
    else if(now == '1') return EXIT;
    else if(now >= 'a' && now <= 'f') return (key_set | (1 << (now - 'a')));
    return key_set;
}

int bfs() {
    int ans = INT_MAX;

    while(!q.empty()) {
        auto pos = q.front(); q.pop();
        //이쪽에서 방문체크를 하면 시간초과남!!!!
        for(int w = 0; w < 4; w++) {
            const int ny = pos.y + dy[w], nx = pos.x + dx[w];
            const int now = getType(ny, nx, pos.key_set);

            if(now == FAIL) continue; //갈 수 없는 길
            else if(now == EXIT) {
                ans = min(ans, pos.cnt + 1);
                break;
            }
            if(pos.cnt + 1 < ans) {
                visited[now][ny][nx] = true; //이쪽에서 방문체크 해줘야함
                q.push(info(ny, nx, now, pos.cnt + 1));
            }
        }

    }
    return ans;
}
// dfs 시간초과 코드
// int dfs(int y, int x, int key_set, int cnt) {
//     int ans = INT_MAX;

//     if(map[y][x] >= 'a' && map[y][x] <= 'f') key_set |= (1 << (map[y][x] - 'a'));

//     visited[key_set][y][x] = true;

//     for(int w = 0; w < 4; w++) {
//         const int ny = y + dy[w], nx = x + dx[w];
//         const char now = getType(ny, nx, key_set);

//         if(now == FAIL) continue; //갈 수 없는 길
//         else if(now == EXIT) return cnt;

//         ans = min(ans, dfs(ny, nx, key_set, cnt + 1));
//     }

//     visited[key_set][y][x] = false;

//     return ans;
// }

int main() {
    scanf("%d %d", &N, &M);
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= M; x++) {
            scanf(" %1c", &map[y][x]);
            if(map[y][x] == '0') q.push(info(y, x, 0, 0));
        }
    }

    visited[0][sy][sx] = true;
    const int ret = bfs(); //dfs(sy, sx, 0, 1);

    printf("%d\n", (ret == INT_MAX ? -1 : ret));
    return 0;
}