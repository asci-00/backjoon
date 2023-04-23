#include <bits/stdc++.h>
#include <queue>
using namespace std;
// 반지름 작은 원 부터 1개의 점(시작점, 끝점)만 포함한 원 개수 새기
// 두 개를 포함하는 원이 생길 경우 종료
class Circle {
public:
    int x, y, r;
    Circle(int _x, int _y, int _r): x(_x), y(_y), r(_r) {}   
};

class Compare
{
public:
    bool operator() (Circle &a, Circle &b)
    {
        return a.r > b.r;
    }
};

int main() { cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int T;
    int sx, sy, ex, ey;
    int cnt, x, y, r;
    int ans;
    
    cin >> T;
    
    while(T--) {
        priority_queue<Circle, vector<Circle>, Compare> q;
        
        ans = 0;
        cin >> sx >> sy >> ex >> ey;
        cin >> cnt;
        
        while(cnt--) {
            cin >> x >> y >> r;
            q.push(Circle(x, y, r));
        }
        
        while(!q.empty()) {
            auto top = q.top(); q.pop();
            
            bool stIncluded = pow(top.r, 2) >= pow(sx - top.x, 2) + pow(sy - top.y, 2);
            bool exIncluded = pow(top.r, 2) >= pow(ex - top.x, 2) + pow(ey - top.y, 2);
            
            if(stIncluded && exIncluded) break;
            ans += (stIncluded + exIncluded);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
