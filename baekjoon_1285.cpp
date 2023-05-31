#include <iostream>
#include <climits>
using namespace std;

int N;
int _map[20];
char input;

int ans = INT_MAX;

void reverseRow(int* arr, int row) {
    arr[row] = (~arr[row] & ((1 << N) - 1));
}

int getTCount(int* arr) {
  int sum = 0;
  
  for(int x = 0; x < N; x++) {
      int cnt = 0;
      for(int y = 0; y < N; y++) {
        if(arr[y] & (1 << x)) cnt ++;
      }
      sum += min(cnt, N - cnt);
  }
  return sum;
}

void dfs(int row) {
    if (row >= N) return;
    int tCnt = getTCount(_map);
    
    ans = min(ans, tCnt);
    
    for(int r = row; r < N; r++) {
        reverseRow(_map, r);
        dfs(r + 1);
        reverseRow(_map, r);
    }
}

int main() {
    scanf("%d ", &N);
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            scanf("%1c ", &input);
            if(input == 'T') _map[y] = _map[y] | (1 << x);
        }
    }
    
    dfs(0);
    
    printf("%d\n", ans);
    return 0;
}
