#include <iostream>

using namespace std;

int N, now = 1, n = 1;

int main() {
    cin >> N;
    
    if(N != 1) {
    
        for(n = 2;; n++) {
            now += (n * 6 - 6);
            if(N <= now) break;
        }
    }
    
    cout << n;
}
