#include <iostream>
#include <vector>

using namespace std;

int R, C, cost, min_cost = 1001, newR;
pair<int, int> min_pos;

vector<char> answer;

const char w[] = {'D', 'U'};
const int d[] = {1, -1};

bool toggle = false;

void move(char ch, int repeat) { for(int r = 1; r <= repeat; r++) answer.push_back(ch); }

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    
    for(int r = 1; r <= R; r++) for(int c = 1; c <= C; c++) {
        cin >> cost;
        if((r + c) % 2 && cost < min_cost) { min_cost = cost; min_pos = make_pair(r, c); }
    }
    
    if(R % 2) { 
        for(int r = 1; r <= R / 2; r++) {
            move('R', C - 1); move('D', 1);
            move('L', C - 1); move('D', 1);
        } move('R', C - 1);
    } else if(C % 2) {
        for(int c = 1; c <= C / 2; c++) {
            move('D', R - 1); move('R', 1);
            move('U', R - 1); move('R', 1);
        } move('D', R - 1);
    } else {
        newR = (min_pos.first % 2 ? min_pos.first : min_pos.first - 1);
        
        for(int r = 1; r <= newR / 2; r++) {    //홀수라인
            move('R', C - 1); move('D', 1);
            move('L', C - 1); move('D', 1);
        }
        
        for(int c = 1; c <= C; c++) {            //newR이 홀수
            if(!(newR + d[toggle] == min_pos.first && c == min_pos.second)) {
                move(w[toggle], 1);
                newR += d[toggle];
                toggle = !toggle;
            } 
            if(c != C) move('R', 1); 
        }
        
        newR = R - newR;
        
        for(int r = 1; r <= newR / 2; r++) {
            move('D', 1); move('L', C - 1); 
            move('D', 1); move('R', C - 1);
        }
    }
    
    for(auto path : answer) cout << path;
    return 0;
}