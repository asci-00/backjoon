#include <bits/stdc++.h>

using namespace std;

int N;
bool _origin[100000], _pressFirstOrigin[100000], _goal[100000];

int cnt1 = 0, cnt2 = 1;

void press(int pos, bool* now) {
    now[pos - 1] = !now[pos - 1];
    now[pos] = !now[pos];
    
    if(pos < N - 1) now[pos + 1] = !now[pos + 1];
}

int main() {
    int input;
    
    scanf("%d", &N);
    
    for(int n = 0; n < N; n++) {
        scanf(" %1d", &input);
        _origin[n] = input;
        _pressFirstOrigin[n] = input;
    }
    
    for(int n = 0; n < N; n++) {
        scanf(" %1d", &input);
        _goal[n] = input;
    }
    
    _pressFirstOrigin[0] = !_origin[0];
    _pressFirstOrigin[1] = !_origin[1];
    
    for(int i = 1; i < N; i++) {
        if(_goal[i - 1] != _origin[i - 1]) {
            press(i, _origin);
            cnt1 ++;
        }
        if(_goal[i - 1] != _pressFirstOrigin[i - 1]) {
            press(i, _pressFirstOrigin);
            cnt2 ++;
        }
    }
    
    int a = _origin[N - 1] == _goal[N - 1] ? cnt1 : N + 1;
    int b = _pressFirstOrigin[N - 1] == _goal[N - 1] ? cnt2 : N + 1;
    
    int ans = min(a, b);
    if(ans == N + 1) printf("-1");
    else printf("%d", ans);
    
    return 0;
} 
