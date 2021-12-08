#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<string>> v;
vector<string> path(15);

void printStrs(vector<string> strs) {
    string depth_str = "";
    
    const int len = strs.size();
    bool flag = false;
    
    for(int depth = 0; depth < len; depth++) {
        if(flag || depth == len - 1 || path[depth] != strs[depth]) {
            path[depth] = strs[depth];
            flag = true;
            cout << depth_str << strs[depth] << '\n';
        }
        
        depth_str += "--";
    }
}

int main() {
    cin >> N;
    for(int n = 0; n < N; n++) {
        cin >> M;
        v.push_back(vector<string>(M));
        
        for(int m = 0; m < M; m++) cin >> v[n][m];
    }
    
    sort(v.begin(), v.end());
    
    
    
    for(auto vs : v) printStrs(vs);
    
    return 0;
}
