#include <bits/stdc++.h>

using namespace std;

class NodeConn {
public:
    NodeConn(int a, int b, int c): from(a), to(b), weight(c) {}
    bool operator > (const NodeConn& op) const { return this->weight > op.weight; }
    bool operator < (const NodeConn& op) const { return this->weight < op.weight; }
    
    int from, to, weight;
};

int V, E, A, B, C, ans, parent[10001];
priority_queue<NodeConn, vector<NodeConn>, greater<NodeConn>> pq;


int _find(int now) {
    if(!parent[now] || parent[now] == now) return (parent[now] = now);
    return (parent[now] = _find(parent[now]));
}

bool _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    
    if(pa == pb) return true;
    
    parent[pb] = pa;
    
    return false;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> V >> E;
    while(E--) {
        cin >> A >> B >> C;
        pq.push(NodeConn(A, B, C));
    }
    
    while(!pq.empty()) {
        auto now = pq.top(); pq.pop();
        if(_union(now.from, now.to)) continue;
        ans += now.weight;
    }
    
    cout << ans;
    return 0;
} 
