#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;
int N, I, diff;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    while(N--) {
        cin >> I;
        
        if(max_heap.size() == 0 || max_heap.top() >= I) max_heap.push(I);
        else min_heap.push(I);
        
        diff = min_heap.size() - max_heap.size();
        
        if(diff >= 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if(diff <= -2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
        cout << max_heap.top() << '\n';
    }
    return 0;
}
