#include <iostream>
#include <cstring>

using namespace std;

int M, x, bit_set;
string op;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> M;
    while(M--) {
        cin >> op;

        if(op == "empty") bit_set = 0;
        else if(op == "all") bit_set = (1 << 21) - 1;

        else {
            cin >> x;
            if(op == "add") bit_set |= (1 << x);
            else if(op == "remove") bit_set &= ~(1 << x);
            else if(op == "toggle") bit_set ^= (1 << x);
            else {
                const int ans = (bit_set & (1 << x)) ? 1 : 0;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}