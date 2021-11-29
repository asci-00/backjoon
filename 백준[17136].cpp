#include <iostream>

using namespace std;

int paper[] = {0, 5, 5, 5, 5, 5};

int leave, min_cost = 26, cnt;
bool map[11][11];

void setPaper(int y, int x, int size, int type) { // type 0 (add) 1 (remove)
    paper[size] = type ? paper[size] + 1 : paper[size] - 1;
    
    register int ny, nx;
    
    for(ny = y; ny < y + size; ny++) {
        for(nx = x; nx < x + size; nx++) {
            map[ny][nx] = type;
        }
    }
}

bool isPossible(int y, int x, int size) {
    register int ny, nx;
    for(ny = y; ny < y + size; ny++) {
        for(nx = x; nx < x + size; nx++) {
            if(!map[ny][nx]) return false;
        }
    }
    
    return true;
}

void dfs(int nxt, int leave, int use) {
    if(min_cost <= use) return;
    if(!leave) { min_cost = use; return; }
    
    for(int now = nxt; now < 100; now++) {
        int ny = now / 10, nx = now % 10;
        
        if(map[ny][nx]) {
            for(int size = 5; size >= 1; size--) {
                if( !paper[size] || !isPossible(ny, nx, size) ) continue;
                
                setPaper(ny, nx, size, 0);
                dfs(now + 1, leave - size*size, use + 1);
                setPaper(ny, nx, size, 1);
            }
            return;
        }
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    for(int y = 0; y < 10; y++) for(int x = 0; x < 10; x++) {
        cin >> map[y][x];
        if(map[y][x]) cnt++;
    }
    
    dfs(0, cnt, 0);
    
    cout << (min_cost > 25 ? -1 : min_cost);
    return 0;
}
