#include <iostream>
#include <queue>
#include <vector>

#define MAX 32000

using namespace std;

bool visited[MAX + 1];
int need[MAX + 1], N, M, a, b;
priority_queue<int, vector<int>, greater<int>> conn[MAX + 1], problem;

// void dfs(int now) {
//     visited[now] = true;
    
//     cout << now << ' ';
    
//     int nxt;
    
//     if(!conn[now].empty()) {    //만약 사전 조건이 제거되었더라도 그 이전 문제가 있다면 해결하고 가야함
//         nxt = conn[now].top();
//         for(int tmp = now + 1; tmp < nxt; tmp++) {
//             if(need[tmp] || visited[tmp]) continue;
//             dfs(tmp);
//         }
//     }
    
    
//     while(!conn[now].empty()) {
//         nxt = conn[now].top(); conn[now].pop();
//         if(!need[nxt] || visited[nxt]) continue;
//         if(--need[nxt] == 0) dfs(nxt);
//     }
// }

int main() { cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M;  //32000, 100000
    
    for(int m = 1; m <= M; m++) {
        cin >> a >> b;  // b를 풀기 위해서는 a를 풀어야함
        need[b]++; 
        conn[a].push(b);
    }
    
    for(int n = 1; n <= N; n++) problem.push(n); 
    
    while(problem.size()) {
        int p = problem.top(); problem.pop();
        if(need[p] || visited[p]) continue;
        
        visited[p] = true; cout << p << ' ';
        
        while(!conn[p].empty()) {
            int nxt = conn[p].top(); conn[p].pop();
            if(--need[nxt] == 0) problem.push(nxt); 
        }
    }
    
    // for(int n = 1; n <= N; n++) {
    //     if(need[n] || visited[n]) continue;   //필요한 선행 문제가 있다면 continue;
    //     dfs(n);
    // }
    
    return 0;
}