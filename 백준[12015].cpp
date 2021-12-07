#include <iostream>
#include <vector>

#define MAX 1000000
using namespace std;

int N, _size, input;
vector<int> dp;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    while(N--) {
        cin >> input;
        
        _size = dp.size();
        if(_size == 0 || dp[_size - 1] < input) dp.push_back(input);
        else {
            if(dp[_size - 1] == input) continue;
            
            const auto lower_value = lower_bound(dp.begin(), dp.end(), input);
            
            if(input < *lower_value) *lower_value = input;
        }
    }
    
    cout << dp.size();
    return 0;
}
