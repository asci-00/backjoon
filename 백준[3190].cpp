#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, L, row, col, _time, nowWay, map[101][101], use = 1;
char way;
bool flag = true;

queue<pair<int, char>> op;
queue<pair<int, int>> snake;
pair<int, int> head, tail, w[] = { {0, -1}, {0, 1} , {-1, 0}, {1, 0} };
//left, right, up, down

const int changeWay[4][2] = {
    {3, 2},  //left L(down) D(up)
    {2, 3},  //right L(up) D(down)
    {0, 1},  //up L(left) D(right)
    {1, 0}   //down L(right) D(left)
};

enum { EMPTY, APPLE, SNAKE };
enum { LEFT, RIGHT, UP, DOWN };
bool isAvailable() {
    const int ny = head.first, nx = head.second;
    
    if(ny <= 0 || nx <= 0 || ny > N || nx > N || map[ny][nx] == SNAKE) {
        flag = false;
        return false;
    }
        
    
    return true;
}

int moveSnake(int way) {
    head = make_pair(
        head.first + w[way].first,
        head.second + w[way].second
    );
    
    if(!isAvailable()) return false;
    
    if(map[head.first][head.second] != APPLE) {
        tail = snake.front();
        
        map[tail.first][tail.second] = EMPTY;
        snake.pop();
    }
    
    snake.push(head);
    map[head.first][head.second] = SNAKE;
    use ++;
    
    return true;
}

bool moveSnake(int d, int end) {
    int cnt = end - use + 1;
    
    while(cnt--) if(!moveSnake(nowWay)) return false;
    
    nowWay = changeWay[nowWay][d];
    return true;
}

int main() { cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    
    for(int k = 1; k <= K; k++) {
        cin >> row >> col;
        map[row][col] = APPLE;
    } cin >> L;
    
    for(int l = 1; l <= L; l++) {
        cin >> _time >> way;
        
        op.push(make_pair(_time, way));
    } 
    
    head = make_pair(1, 1);
    map[1][1] = SNAKE;
    snake.push(head);
    
    nowWay = RIGHT;
    
    while(!op.empty()) {
        const auto n = op.front(); op.pop();
        if(!moveSnake(n.second == 'L' ? 0 : 1, n.first)) break;
    }
    
    if(flag) while(moveSnake(nowWay));
    
    cout << use;
    
    return 0;
}
