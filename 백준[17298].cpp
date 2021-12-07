#include <iostream>

using namespace std;

int input[1000001];
int NGE_idx[1000001];

int N, now;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int n = 1; n <= N; n++) cin >> input[n];
    
    NGE_idx[N] = -1;
    
    for(int n = N - 1; n > 0; n--) {
        if(input[n] < input[n + 1]) NGE_idx[n] = n + 1;
        else {
            now = NGE_idx[n + 1];
            while(now > 0 && input[n] >= input[now]) now = NGE_idx[now];
            
            NGE_idx[n] = now;
        }
    }
    
    for(int n = 1; n <= N; n++) {
        if(NGE_idx[n] > 0) now = input[NGE_idx[n]];
        else now = -1;
        
        cout << now << ' ';
    }
    return 0;
}
