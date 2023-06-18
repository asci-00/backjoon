#include <iostream>
#include <climits>

using namespace std;

class Pos {
public:
    Pos(int _y, int _x): y(_y), x(_x) {}
    Pos(): y(0), x(0) {}
    
    int y;
    int x;
    Pos& operator =(const Pos &op) {
        this->y = op.y;
        this->x = op.x;
        
        return *this;
    }
    
    bool operator ==(const Pos& op) {
        return this->y == op.y && this->x == op.x;
    }
};

int N, M, ans = INT_MAX;
char field[11][11];

Pos iR, iB;
const Pos directions[4] = {
    Pos(-1, 0),
    Pos(0, -1),
    Pos(+1, 0),
    Pos(0, +1),
};

Pos move(Pos target, Pos direction, Pos NR, Pos NB) {
    while(true) {
        target.y += direction.y;
        target.x += direction.x;
        
        if(field[target.y][target.x] == 'O') return target;
        if(target == NR || target == NB || field[target.y][target.x] == '#') {
            target.y -= direction.y;
            target.x -= direction.x;
            return target;
        }
    }
}

void dfs(Pos R, Pos B, int cnt) {
    if(cnt > 10 || cnt >= ans) return;
    
    Pos NR, NB;

    for(int d_idx = 0; d_idx < 4; d_idx++) {
        auto d = directions[d_idx];
        
        if(
            (d_idx == 0 && B.y < R.y) ||    // top
            (d_idx == 1 && B.x < R.x) ||    // left
            (d_idx == 2 && B.y > R.y) ||    // down
            (d_idx == 3 && B.x > R.x)       // right
        ) {
            NB = move(B, d, NR, NB);
            NR = move(R, d, NR, NB);
        } else {
            NR = move(R, d, NR, NB);
            NB = move(B, d, NR, NB);
        }
        
        
        if(field[NB.y][NB.x] == 'O' || (NB == B && NR == R)) continue;
        if (field[NR.y][NR.x] == 'O') {
            ans = min(ans, cnt);
            return;
        }
        
        dfs(NR, NB, cnt + 1);
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    char ch;

    for(int y = 1; y <= N; y++) {
        for(int x = 1; x <= M; x++) {
            cin >> ch;
            if(ch == 'R') iR = Pos(y, x);
            else if(ch == 'B') iB = Pos(y, x);
            else field[y][x] = ch;
        }
    }
    
    dfs(iR, iB, 1);
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}
