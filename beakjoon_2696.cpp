#include <bits/stdc++.h>

using namespace std;

vector<int> solution() {
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, less<int>> maxQ;
    
    int N, _input;
    vector<int> ans;
    
    cin >> N;
    for(int n = 1; n <= N; n++) {
        cin >> _input;
        if(minQ.size() > maxQ.size()) maxQ.push(_input);
        else minQ.push(_input);
        
        while(minQ.size() && maxQ.size() && minQ.top() < maxQ.top()) {
            auto _max = minQ.top(); minQ.pop();
            auto _min = maxQ.top(); maxQ.pop();
            
            minQ.push(_min);
            maxQ.push(_max);
        }
        
        if(n % 2 == 1) ans.push_back(minQ.top()); 
    }
    
    return ans;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int T;
    
    cin >> T;
    while(T--) {
        // 출력 조건
        // 출력한 중앙값 개수
        // 중앙값 목록 (공백으로 구분 + 한 줄에 최대 10개)
        
        auto ans = solution();
        cout << ans.size() << '\n';
        
        int idx = 0;
        
        for(int seq_item: ans) { cout << seq_item << ' '; if(++idx % 10 == 0) cout << '\n'; }
        if(idx % 10) cout << '\n';
    }
    
    return 0;
}
