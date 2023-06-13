#include <iostream>

using namespace std;

int N;
unsigned long long dp[33][33][3];
bool _map[33][33];

int wy[] = {0, 1, 1};
int wx[] = {1, 0, 1};

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= N; x++) {
            cin >> _map[y][x];
        }
    }
    
    dp[1][2][0] = 1;
    
    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= N; x++) {
            if(_map[y][x]) continue;
            
            for(int w = 0; w < 3; w++) {
                int ny = y + wy[w];
                int nx = x + wx[w];
                
                if(ny > N || nx > N) continue;
                
                if(w == 2) {
                    if(_map[ny][nx - 1] || _map[ny - 1][nx] || _map[ny][nx]) continue;
                    dp[ny][nx][w] += (dp[y][x][0] + dp[y][x][1] + dp[y][x][2]);
                } else {
                    if(_map[ny][nx]) continue;
                    dp[ny][nx][w] += (dp[y][x][2] + dp[y][x][w]);
                }
            }
        }
    }
    
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    
    return 0;
}
