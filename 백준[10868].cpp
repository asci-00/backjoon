#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int tree[1 << 18] = {0, };
int start, _size, N, M, a, b;

int initTree(int node) { 
    if(tree[node]) return tree[node];
    tree[node] = min(initTree(node * 2), initTree(node * 2 + 1));   //해당 범위 내 가장 작은 값
    return tree[node];
}

int find(int s, int e, int rs, int re, int node) {
    if(s == rs && e == re) return tree[node];
    
    const int mid = (s + e) / 2;
    
    if(rs > mid) return find(mid + 1, e, rs, re, node * 2 + 1); //rs <= mid
    else if(re <= mid) return find(s, mid, rs, re, node * 2);   //re > mid
    
    else return min(
        find(s, mid, rs, mid, node * 2), 
        find(mid + 1, e, mid + 1, re, node * 2 + 1)
    );
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    
    for(_size = 1; _size < N; _size*=2);
    
    start = _size - 1;
    for(int n = 1; n <= _size; n++) {
        if(n > N) tree[start + n] = INT_MAX;
        else cin >> tree[start + n];
    }
    initTree(1);
    
    for(int m = 1; m <= M; m++) {
        cin >> a >> b;
        cout << find(1, _size, a, b, 1) << '\n';
    }
    
    return 0;
}
