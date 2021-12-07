#include <iostream>
#include <vector>

using namespace std;

vector<int> ancestor;
int N, M, from, to, ans;

int _find(int node) {
    if(ancestor[node] == node) return node;
    return (ancestor[node] = _find(ancestor[node]));
}

void _union(int a, int b) {
    int anc_a = _find(a);
    int anc_b = _find(b);
    
    ancestor[anc_a] = anc_b;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    
    ancestor = vector<int>(N);
    
    for(int n = 0; n < N; n++) ancestor[n] = n;
    
    for(int m = 1; m <= M; m++) {
        cin >> from >> to;
        if(_find(from) == _find(to) && ans == 0) ans = m;
        else _union(from, to);
    }
    
    cout << ans;
    
    return 0;
}
