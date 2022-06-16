#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dp[3] = {0, 1, 1};
    
    n --;
    
    while(n --) {
        dp[2] = (dp[0] + dp[1]) % 1234567;
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
