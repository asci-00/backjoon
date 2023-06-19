#include <bits/stdc++.h>
using namespace std;

class Pos {
public:
  Pos(int _y, int _x, int _w): y(_y), x(_x), w(_w) {}
  Pos(int _y, int _x): y(_y), x(_x) {}
  Pos(): y(0), x(0) {}

  int y, x, w;
  
  Pos operator +(const Pos& op) const { return Pos(this->y + op.y, this->x + op.x); }
  bool operator <(const Pos &op) const { return this->w < op.w; }
  bool operator >(const Pos &op) const { return this->w > op.w; }

};

const Pos dicts[] = {
  Pos(-1, 0),
  Pos(0, -1),
  Pos(+1, 0),
  Pos(0, +1)
};

int N, M, field[12][12], _max, ans;
int parent[7];
bool visited[12][12];
queue<Pos> q;
priority_queue<Pos, vector<Pos>, greater<Pos>> edges;

void bfs(int y, int x, int c) {
  q.push(Pos(y, x));

  visited[y][x] = true;
  field[y][x] = c;
  parent[c] = c;
  
  while(!q.empty()) {
    Pos _now = q.front(); q.pop();

    for (auto d: dicts) {
      Pos _next = _now + d;
      if(visited[_next.y][_next.x] || !field[_next.y][_next.x]) continue;
      visited[_next.y][_next.x] = true;
      field[_next.y][_next.x] = c;

      q.push(_next);
    }
  }
}

void setGraph() {
  int _from, _to, _len;

  for (int n = 1; n <= N; n++) { // 가로 방향
    _from = _to = _len = 0;
    for (int m = 1; m <= M; m++) {
      if(field[n][m] == _from) { _len = 0; continue; }
      if(!field[n][m]) { _len ++; continue; }

      if(_from) {
        _to = field[n][m];

        if(_len >= 2) edges.push(Pos(_from, _to, _len));
        _from = _to;
        _len = 0;
      }
      else _from = field[n][m];
    }
  }

  

  for (int m = 1; m <= M; m++) { // 세로 방향
    _from = _to = _len = 0;
    for (int n = 1; n <= N; n++) {
      if(field[n][m] == _from) { _len = 0; continue; }
      if(!field[n][m]) { _len ++; continue; }

      if(_from) {
        _to = field[n][m];

        if(_len >= 2) edges.push(Pos(_from, _to, _len));
        _from = _to;
        _len = 0;
      }
      else _from = field[n][m];
    }
  }
}

int _find(int n) {
    if(parent[n] == n) return n;
    return parent[n] = _find(parent[n]);
}

bool _union(int x, int y) {
    int px = _find(parent[x]);
    int py = _find(parent[y]);
    
    if(px == py) return false;
    
    parent[py] = parent[px];
    return true;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
  cin >> N >> M;
  for (int n = 1; n <= N; n++) {
      for (int m = 1; m <= M; m++) {
        cin >> field[n][m];
      }
  }

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      if(visited[n][m] || !field[n][m]) continue;
      bfs(n, m, ++_max);
    }
  }

  setGraph();

  while(!edges.empty() && _max > 1) {
    auto edge = edges.top(); edges.pop();
    if(_union(edge.x, edge.y)) {
        ans += edge.w;
        --_max;
    }
  }
  
  cout << (_max > 1 ? -1 : ans);

  return 0;
}
