#include <bits/stdc++.h>
#define _MOD 10007

using namespace std;

int N, M, H;
string str;
int caseCount[51][1001];
vector<int> blocks[51];

vector<int> split(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, delimiter)) answer.push_back(stoi(temp));
    return answer;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> H; cin.get();
    for(int n = 1; n <= N; n++) {
        getline(cin, str, '\n');
        blocks[n] = split(str, ' ');
    }
    
    caseCount[1][0] = 1;
    for(int block: blocks[1]) caseCount[1][block] = 1;
    
    for(int n = 2; n <= N; n++) { // 최대 50
        for(int _now = 0; _now <= H; _now++)
            caseCount[n][_now] = caseCount[n - 1][_now];
        
        for(int block: blocks[n]) { // 최대 10
            for(int _now = block; _now <= H; _now++) { // 최대 1000
                if(!caseCount[n - 1][_now - block]) continue;
                caseCount[n][_now] = (caseCount[n][_now] + caseCount[n - 1][_now - block]) % _MOD;
            }
        }
    }
    
    cout << caseCount[N][H] << '\n';
    
    return 0;
}
