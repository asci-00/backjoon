#include <iostream>

using namespace std;

unsigned int A, B, V, ans;

int main() {
    cin >> A >> B >> V;
    
    V -= A;
    
    ans = V / (A - B) + 1;
    
    if(V % (A - B)) ans ++;
    
    cout << ans;
    return 0;
}
