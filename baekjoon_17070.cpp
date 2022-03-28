#include <iostream>

using namespace std;

int N, map[17][17], dp[17][17];
enum { RIGHT, DOWN, RIGHTDOWN };
bool checkDiagonal(int y, int x) {
    return ( x < N && y < N && !map[y][x + 1] && !map[y + 1][x] );
}
void dfs(int y, int x, int way) {
    if(y > N || x > N || map[y][x]) return;
    dp[y][x] += 1;
    if(checkDiagonal(y, x)) dfs(y + 1, x + 1, RIGHTDOWN);
    switch(way) {
        case RIGHT:
            dfs(y, x + 1, RIGHT);
            break;
        case DOWN:
            dfs(y + 1, x, DOWN);
            break;
        case RIGHTDOWN:
            dfs(y, x + 1, RIGHT);
            dfs(y + 1, x, DOWN);
            break;
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;    
    for(int r = 1; r <= N; r++) for(int c = 1; c <= N; c++) cin >> map[r][c];    
    dfs(1, 2, RIGHT);
    cout << dp[N][N];    
    return 0;
}
