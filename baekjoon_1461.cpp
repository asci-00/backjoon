#include <bits/stdc++.h>

using namespace std;

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int N, M, I, now_books_cnt, ans;
    priority_queue<int, vector<int>, less<int>> books[2];
    
    cin >> N >> M;
    while(N--) {
        cin >> I;
        
        books[I > 0 ? 0 : 1].push(abs(I));
    }
    
    int max_dist = max(
        books[0].empty() ? 0 : books[0].top(), 
        books[1].empty() ? 0 : books[1].top()
    );
    
    now_books_cnt = 0;
    ans = 0;
    
    while(!books[0].empty()) {
        int now_books = books[0].top();
        books[0].pop();
        
        if(now_books_cnt) {
            now_books_cnt --;
            continue;
        }
        now_books_cnt = M - 1;
        ans += now_books;
    }
    
    now_books_cnt = 0;
    
    while(!books[1].empty()) {
        int now_books = books[1].top();
        books[1].pop();
        
        if(now_books_cnt) {
            now_books_cnt --;
            continue;
        }
        
        now_books_cnt = M - 1;
        ans += now_books;
    }
    
    cout << ans * 2 - max_dist << '\n';
    
    return 0;
}
