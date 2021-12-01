#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> end_time;
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> schedule;

int N, a, b, ans = 1;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int n = 1; n <= N; n++) {
        cin >> a >> b;
        schedule.push(make_pair(a, b));
    }
    
    auto now = schedule.top(); schedule.pop();
    end_time.push(now.second);
    
    while(!schedule.empty()) {
        now = schedule.top(); schedule.pop();
        if(end_time.top() <= now.first) end_time.pop();
        else ans ++;
        end_time.push(now.second);
    }
    
    cout << ans;
    return 0;
}
