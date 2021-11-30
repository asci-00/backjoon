#include <iostream>
#include <climits>
#include <vector>

using namespace std;

pair<int, int> tree[1 << 18];   //0번째 최소값 1번째 최대값
int start, _size, N, M, a, b;

pair<int, int> initTree(int node) { 
    if(tree[node].first) return tree[node];
    
    const auto leftChild = initTree(node * 2), rightChild = initTree(node * 2 + 1);
    
    tree[node].first = min(leftChild.first, rightChild.first);   //해당 범위 내 가장 작은 값
    tree[node].second = max(leftChild.second, rightChild.second);
    
    return tree[node];
}

pair<int, int> find(int s, int e, int rs, int re, int node) {
    if(s == rs && e == re) return tree[node];
    
    const int mid = (s + e) / 2;
    
    if(rs > mid) return find(mid + 1, e, rs, re, node * 2 + 1); //rs <= mid
    else if(re <= mid) return find(s, mid, rs, re, node * 2);   //re > mid
    
    const auto left = find(s, mid, rs, mid, node * 2), right = find(mid + 1, e, mid + 1, re, node * 2 + 1);
    
    return make_pair(
        min(left.first, right.first),
        max(left.second, right.second)
    );
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    
    for(_size = 1; _size < N; _size*=2);
    
    start = _size - 1;
    
    
    for(int n = 1; n <= _size; n++) {
        if(n > N) {
            tree[start + n].first = INT_MAX;
        }
        else {
            cin >> tree[start + n].first;
            tree[start + n].second = tree[start + n].first;
        }
    }
    initTree(1);
    
    for(int m = 1; m <= M; m++) {
        cin >> a >> b;
        
        const auto ans = find(1, _size, a, b, 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    
    return 0;
}
