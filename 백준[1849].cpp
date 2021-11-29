#include <iostream>
#include <vector>

using namespace std;

int tree[262144] = {0, };
int pos[100000] = {0, }, answer[100000];
int start, _size, N;

void initTree() { for(int n = start + N - 1; n > 1; n--) tree[n / 2] += tree[n]; }

void use(int node, int num, int seq) {
    
    tree[node]--;
    
    if(node >= start) {
        answer[node - start] = num;
        return;
    }
    
    if(tree[node * 2] > seq) use(node * 2, num, seq);
    else use(node * 2 + 1, num, seq - tree[node * 2]);
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    for(_size = 1; _size < N; _size*=2); _size *= 2; // 총 개수 = size - 1
    
    start = _size / 2;
    
    for(int n = 0; n < N; n++) {
        cin >> pos[n];
        tree[start + n] = 1;
    }
    initTree();
    
    for(int n = 0; n < N; n++) use(1, n + 1, pos[n]);
    
    for(int n = 0; n < N; n++) cout << answer[n] << '\n';
    
    return 0;
}
