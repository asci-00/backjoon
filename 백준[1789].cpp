#include <iostream>

using namespace std;

long long sum, cnt, S;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> S;
    
    for(cnt = 1; sum <= S; cnt++) sum += cnt;
    cout << cnt - 2;
}
