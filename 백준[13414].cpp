#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

map<string, bool> m;
stack<string> answer;
vector<string> num;

int K, L;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> K >> L;
    
    num = vector<string>(L + 1);
    for(int i = 1; i <= L; i++) cin >> num[i];
    for(int i = L; i >= 1; i--) {
        if(m.find(num[i]) != m.end()) continue;
        
        m.insert(make_pair(num[i], true));
        answer.push(num[i]);
    }
    
    for(int i = 1; i <= K && !answer.empty(); i++) {
        cout << answer.top() << '\n'; answer.pop();
    }
    return 0;
}
