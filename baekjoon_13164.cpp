#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int N, K, _prev, _now;
    ull _sum = 0;
    vector<ull> v;
    
    cin >> N >> K;
    
    for(int n = 0; n < N; n++) {
        cin >> _now;
        
        if(n - 1 < 0) { 
            _prev = _now;
            continue;
        }
        
        v.push_back(_now - _prev);
        _prev = _now;
    }
    
    sort(v.begin(), v.end(), less<>());
    
    for(int k = 0; k < K - 1; k++) v.pop_back();
    
    for(int _val : v) _sum += _val;
    
    cout << _sum;
    
    return 0;
}
