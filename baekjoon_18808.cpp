#include <bits/stdc++.h>

using namespace std;

int N, M, K, h, w, ans;

pair<int, int> _size[100];
bool _map[40][40];
bool** pieces[100];
int filled_cnt[100];

bool** rotate90(bool **piece, int h, int w) {
    bool **piece_next = new bool*[w];
    for(int y = 0; y < w; y++) {
        piece_next[y] = new bool[h];
        for(int x = 0; x < h; x++) {
            piece_next[y][(h - 1) - x] = piece[x][y];
        }
    }
    
    return piece_next;
}

bool _check(bool **piece, int y, int x, int h, int w) {
    for(int ny = y; ny < y + h; ny++) {
        for(int nx = x; nx < x + w; nx++) {
            if(_map[ny][nx] && piece[ny - y][nx - x]) return false;
        }
    }
    return true;
}

void _fill(bool **piece, int y, int x, int h, int w) {
    for(int ny = y; ny < y + h; ny++) {
        for(int nx = x; nx < x + w; nx++) {
            if(piece[ny - y][nx - x]) _map[ny][nx] = true;
        }
    }
}

bool _apply(bool **piece, int h, int w) {
    for(int y = 0; y <= N - h; y++) {
        for(int x = 0; x <= M - w; x++) {
            if(_check(piece, y, x, h, w)) {
                _fill(piece, y, x, h, w);
                return true;
            }
        }
    }
    return false;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    
    for(int s = 0; s < K; s++) {
        cin >> h >> w;
        
        _size[s] = make_pair(h, w);
        
        bool **piece = new bool*[h];
        for(int y = 0; y < h; y++) {
            piece[y] = new bool[w];
            for(int x = 0; x < w; x++) {
                cin >> piece[y][x];
                if(piece[y][x]) filled_cnt[s] ++;
            }
        }
        pieces[s] = piece;
    }
    
    for(int s = 0; s < K; s++) {
        if(N * M - ans < filled_cnt[s]) continue;
        
        bool** now_piece = pieces[s];
        int h = _size[s].first;
        int w = _size[s].second;
        
        for(int r = 0; r < 4; r++) { // 회전
            if(_apply(now_piece, h, w)) {
                ans += filled_cnt[s];
                break;
            }
            
            now_piece = rotate90(now_piece, h, w);
            swap(h, w);
        }
    }
    
    cout << ans;
    
    return 0;
}
