#include <iostream>
#include <cmath>

using namespace std;

int number_cnt[10];
int N, start = 1;

void subCount(int n, int w) {
    while (n) {
        number_cnt[n % 10] += pow(10, w);
        n /= 10;
    }
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0;; i++) {
        while(N % 10 != 9 && start <= N) {
            subCount(N, i);
            N--;
        }

        while(start % 10 != 0 && start <= N) {
            subCount(start, i);
            start++;
        }

        if (start > N) break;

        for (int j = 0; j < 10; j++) {
            number_cnt[j] += (N / 10 - start / 10 + 1) * (int)pow(10, i);
        }
        N /= 10;
        start /= 10;
    }

    for(int num: number_cnt) cout << num << ' ';
    return 0;
}
