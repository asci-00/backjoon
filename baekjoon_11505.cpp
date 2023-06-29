#include <bits/stdc++.h>

#define _MOD 1000000007
using namespace std;
class IndexTree {
public:
  int _leaf;
  int _size;
  vector <int> _tree;
  IndexTree(int N) {
    for (_leaf = 1; _leaf < N; _leaf *= 2);
    _size = _leaf * 2;
    _tree.resize(_size);
  }
  int multi(int num1, int num2) {
    return (num1 * (unsigned long long)num2) % _MOD;
  }
  void updateTree(int index) {
    if (!index) return;
    _tree[index] = multi(_tree[2 * index], _tree[2 * index + 1]);
    updateTree(index / 2);
  }
  int initTree(int n = 1) {
      if(n < _leaf) _tree[n] = multi(initTree(2 * n), initTree(2 * n + 1));
      return _tree[n];
  }
  void update(int order, int val) {
    int index = _leaf + order - 1;
    _tree[index] = val;
    updateTree(index / 2);
  }
  int query(int begin, int end) {
    int L = _leaf + begin - 1;
    int R = _leaf + end - 1;
    int result = 1;
    
    if(L > R) return 0;
    
    while (L < R) {
      int nextL = (L + 1) / 2;
      int nextR = (R - 1) / 2;
      if (nextL != L / 2) result = multi(result, _tree[L]);
      if (nextR != R / 2) result = multi(result, _tree[R]);
      L = nextL;
      R = nextR;
    }
    if (L == R) result = multi(result, _tree[L]);
    return result;
  }
};
int N, M, K, _input, b, c;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
  cin >> N >> M >> K;
  IndexTree _tree = IndexTree(N);
  
  for (int n = _tree._leaf; n < _tree._size; n++) {
    if(n < _tree._leaf + N) cin >> _input;
    else _input = 1;
    _tree._tree[n] = _input;
  }
  _tree.initTree();
  
  for (int i = 1; i <= M + K; i++) {
    cin >> _input >> b >> c;
    if (_input == 1) _tree.update(b, c);
    else cout << _tree.query(b, c) << '\n';
  }
  
  return 0;
}
