#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int T, N, I;
ull sum, new_ch, a, b;
priority_queue<ull, vector<ull>, greater<ull>> pq;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> N;
        
        sum = 0;
        pq = priority_queue<ull, vector<ull>, greater<ull>>();
        
        while(N--) {
            cin >> I;
            pq.push(I);
        }
        
        while(pq.size() >= 2) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            
            new_ch = a + b;
            sum += new_ch;
            
            pq.push(new_ch);
        }
        
        cout << sum << '\n';
    }
    return 0;
}
