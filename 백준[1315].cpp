#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Q {
    public:
    Q(int s, int i, int p) : _str(s), _int(i), _point(p) {}
    int _str, _int, _point;
};

vector<Q> QList;

int N, ans, nPNT, solve, s, q, p, lPNT[1001][1001];
bool DP[1001][1001];

/*
DP[STR][INT] : STR & INT 인 상태가 존재할 수 있는지 여부
lPNT[STR][INT] : STR & INT 인 상태에서 남은 포인트
*/

int main() { ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int n = 1; n <= N; n++) {
        cin >> s >> q >> p;
        QList.emplace_back(s, q, p);
    }

    for(int nSTR = 1; nSTR <= 1000; nSTR++)
    for(int nINT = 1; nINT <= 1000; nINT++) {
        if(!(
            (nSTR == 1 && nINT == 1) ||
            (DP[nSTR - 1][nINT] && lPNT[nSTR - 1][nINT] >= 1 && nSTR > 1) ||
            (DP[nSTR][nINT - 1] && lPNT[nSTR][nINT - 1] >= 1 && nINT > 1)
        )) continue;    //STR & INT != 1 또는 이전 상태가 존재할 수 없는 경우 continue

        nPNT = 2; solve = 0;  //처음 상태가 되기 위해서는 STR(0) INT(0) 에서 2포인트가 필요함
        for(auto nQ : QList) {
            if(nSTR >= nQ._str || nINT >= nQ._int) { nPNT += nQ._point; solve ++; } //해당 조건을 만족하면 푼 문제 수 ++ & 포인트 증가
        }
        lPNT[nSTR][nINT] = nPNT - (nSTR + nINT);    //현재 가진 포인트 중 지금의 STR과 INT 를 만들기 위한 포인트를 제거
        ans = max(ans, solve);
        DP[nSTR][nINT] = true;
    }

    cout << ans;
    return 0;
}