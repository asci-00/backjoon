#include <iostream>
#include <stack>

using namespace std;

int N, _size, arr[1001], dp[1001], parent[1001], max_idx;
stack<int> ans;

void print(int n) {
    if(n == 0) return;
    
    print(parent[n]);
    cout << arr[n] << ' ';
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int n = 1; n <= N; n++) {
        cin >> arr[n];
        
        max_idx = 0;
        
        for(int nxt = 1; nxt < n; nxt++) {
            if(arr[n] > arr[nxt] && dp[max_idx] < dp[nxt]) {
                max_idx = nxt;
            }
        }
        parent[n] = max_idx;
        dp[n] = dp[max_idx] + 1;
    }
    
    max_idx = 0;
    
    for(int n = 1; n <= N; n++) if(dp[max_idx] < dp[n]) max_idx = n; 
    while(max_idx) { 
        ans.push(arr[max_idx]);
        max_idx = parent[max_idx];
    }
    
    cout << ans.size() << '\n';
    
    while(!ans.empty()) { cout << ans.top() << ' '; ans.pop(); }
    return 0;
}
