#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iipair

int T, N, M, ans;
vector<iipair> v;
vector<bool> used;

/* 잘못짠 코드
struct compare {
    bool operator () (const iipair& a, const iipair& b) const {
        if(a.first == b.first) return (a.second - a.first) < (b.second - b.first);
        return a.first > b.first;
    }
};

typedef priority_queue <
    iipair,
    vector<iipair>,
    compare
> pq_type;

pq_type r_pq;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        r_pq = pq_type(); nxt = 1; ans = 0;
        while(M--) {
            cin >> a >> b;
            r_pq.push(make_pair(a,b));
        }

        while(!r_pq.empty() && nxt <= N) {
            auto now = r_pq.top(); r_pq.pop();

            if(nxt < now.first) {
                nxt = now.first;
                if(nxt > N) break;
            }
            if(nxt > now.second) continue;
            nxt ++;
            ans ++;
        }

        cout << ans << '\n';
    }

    return 0;
}
*/

bool cmp(const iipair a, const iipair b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        v = vector<iipair>(M); used = vector<bool>(N + 1); ans = 0;
        for(int m = 0; m < M; m++) cin >> v[m].first >> v[m].second;
        sort(v.begin(), v.end(), cmp);

        for(auto p : v) for(int idx = p.first; idx <= p.second; idx++) {
            if(used[idx]) continue;
            used[idx] = true;
            ans++;
            break;
        }

        cout << ans << '\n';
    }

    return 0;
}