#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100
#define DIR_NUM 4
#define ASCII_NUM 128

int n, m, k;
bool apple[MAX_N+1][MAX_N+1];

vector<pair<int, int>> snake;

int dx[DIR_NUM] = {1, -1, 0, 0};
int dy[DIR_NUM] = {0, 0, 1, -1};

int mapper[ASCII_NUM];
int ans;

bool CanGo(int x, int y) {
    return 1<=x && x<=n && 1<=y && y<=n;
}

bool IsTwisted(pair<int, int> newHead) {
    for(int i=0; i<(int)snake.size(); i++) {
        if(newHead == snake[i]) return true;
    }

    return false;
}

// 새로운 머리 추가
bool PushFront(pair<int, int> newHead) {
    // 몸이 꼬이면
    if(IsTwisted(newHead) == true)
        return false;
    
    snake.insert(snake.begin(), newHead);

    return true;
}

// 꼬리 삭제
void PopBack() {
    snake.pop_back();
}

// nx, ny 쪽으로 뱀 이동
bool MoveSnake(int nx, int ny) {
    // 이동할 곳에 사과가 존재한다면
    if(apple[nx][ny] == true) {
        apple[nx][ny] = false;

        // 이동한 머리에 몸이 꼬이면 false
        if(PushFront(make_pair(nx, ny)) == false)
            return false;
    } else {
        // 사과가 없을 때 꼬리 삭제
        PopBack();

        // 이동한 머리에 몸이 꼬이면 false
        if(PushFront(make_pair(nx, ny)) == false)
            return false;
    }

    return true;
}

bool Move(int dir, int num) {
    // num 횟수만큼 뱀 이동
    // 한 번 움직일때마다 갱신
    while(num--) {
        ans++;

        pair<int, int> head = snake.front();

        int nx = head.first+dx[dir];
        int ny = head.second+dy[dir];

        if(CanGo(nx, ny) == false) return false;

        if(MoveSnake(nx, ny) == false) return false;
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    mapper['D'] = 0;
    mapper['U'] = 1;
    mapper['R'] = 2;
    mapper['L'] = 3;

    cin >>n>>m>>k;

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x>>y;
        apple[x][y] = true;
    }

    snake.push_back(make_pair(1, 1));
    for(int i=0; i<k; i++) {
        char dir;
        int num;
        cin >>dir>>num;

        if(Move(mapper[dir], num) == false) break;
    }

    cout << ans;
    return 0;
}