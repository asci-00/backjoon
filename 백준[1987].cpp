#include <iostream>
#include <algorithm>

#define MAX 20

using namespace std;

const int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int visited, R, C;
char map[MAX + 2][MAX + 2];

int dfs(int visited, int y, int x, int len) {
    int ret = len;
    for(int w = 0; w < 4; w++) {
        int ny = y + dy[w], nx = x + dx[w];
        if( !map[ny][nx] || //범위를 넘어간 경우
            visited & (1 << map[ny][nx])  //이미 방문한 알파벳인경우
        ) continue;
        ret = max(
            ret,
            dfs(visited | (1 << map[ny][nx]), ny, nx, len + 1)
        );
    }
    return ret;
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int y = 1; y <= R; y++) for(int x = 1; x <= C; x++) { cin >> map[y][x]; map[y][x] -= ('A' - 1); }

    cout << dfs(1 << map[1][1], 1, 1, 1);
    return 0;
}