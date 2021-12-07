#include <iostream>
using namespace std;

unsigned long long dp[101] = {0, 1, 1, 1, 2, 2}, T, N;

unsigned long long getP(int  N) {
    if(!dp[N]) dp[N] = getP(N - 1) + getP(N - 5); 
    return dp[N];
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> T;
    
    while(T--) {
        cin >> N;
        cout << getP(N) << '\n';
    }
    return 0;
}
