#include <iostream>
#include<algorithm>
#include <cstring>

using namespace std;

string S, T;

bool solution() {
    int sLen = S.length(), tLen = T.length();
    char ch;
    
    if(sLen > tLen) return 0;
    
    while(sLen <= tLen) {
        if(S == T) return 1;
        ch = T[--tLen];
        
        T.pop_back();
        
        if(ch == 'B') reverse(T.begin(), T.end());
    }
    
    return 0;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> S >> T;
    
    cout << solution();
    return 0;
}
