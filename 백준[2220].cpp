#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, _size;
queue<int> node;
vector<int> tree, value;

int moveNodes(int node, int hist) {
    if(node == 0) return tree[1];
    
    int tmp = tree[node];
    tree[node] = hist;
    
    return moveNodes(node / 2, tmp);
}


int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    tree = vector<int>(N + 1); value = vector<int>(N + 1);
    value[1] = N;
    
    node.push(1);
    
    _size = N;
    
    for(int n = 1; n <= N; n++) tree[n] = n;
    
    while(--_size) node.push(moveNodes(_size, N));
    
    for(int n = N; n >= 1; n--, node.pop()) value[node.front()] = n;
    for(int n = 1; n <= N; n++) cout << value[n] << ' ';
    return 0;
}
