#include <iostream>
#include <vector>

using namespace std;

vector<int> prdr, ordered;

int N, K, input, mid;
unsigned long long sum;

void insertNode(int s, int e, int n) {
    //ordered 삽입 위치  찾기
    if(s >= e) {
        if(ordered.size() > s && ordered[s] < n)
            ordered.insert(ordered.begin() + s + 1, n);
        else ordered.insert(ordered.begin() + s, n);
        return;
    }
    
    const int mid = (e + s) / 2;
    
    if(n < ordered[mid]) insertNode(s, mid - 1, n);
    else insertNode(mid + 1, e, n);
    
}

void removeNode(int s, int e, int n) {
    const int mid = (e + s) / 2;
    
    if(n < ordered[mid]) removeNode(s, mid - 1, n);
    else if(n > ordered[mid]) removeNode(mid + 1, e, n);
    else {
        ordered.erase(ordered.begin() + mid, ordered.begin() + mid + 1);
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    
    mid = (K + 1) / 2; prdr.push_back(-1); ordered.push_back(-1);   //1부터 세기 위해
    
    for(int n = 1; n <= N; n++) {
        cin >> input;
        
        prdr.push_back(input);
        
        insertNode(1, min(n, K), input);
        
        if(n >= K) {
            sum += ordered[mid];
            removeNode(1, K, prdr[n - K + 1]);
        }
    }
    
    cout << sum;
    return 0;
}
