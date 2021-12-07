#include <iostream>
#include <queue>

using namespace std;

int N, M, i, now_crain, min_time;
priority_queue<int, vector<int>, greater<int>> crain, fre;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N; for(int n = 0; n < N; n++) { cin >> i; crain.push(i); }
    cin >> M; for(int m = 0; m < M; m++) { cin >> i; fre.push(i); }
    
    int min_time = 1;
    
    while(!crain.empty()) {
        now_crain = crain.top();
        min_time = fre.size() / crain.size(); crain.pop();
        
        for(i = 1; !fre.empty() && i <= min_time; i++) {
            if(now_crain >= fre.top()) fre.pop();
            else break;
        }
    }
    
    while(!fre.empty()) {
        if(now_crain >= fre.top()) {
            min_time ++;
            fre.pop();
        } else break;
    }

    cout<< (fre.empty() ? min_time : -1);
    return 0;
}
