#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX_N 100
#define ASCII 128
#define DIR_NUM 4

int n, m, k, ans;
bool apple[MAX_N][MAX_N];
int mapper[ASCII];
int dx[DIR_NUM] = {-1, 1, 0, 0}, dy[DIR_NUM] = {0, 0, 1, -1};
vector<pair<int, int>> snake;

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

bool IsTwisted(pair<int, int> newHead) {
    for(int i=0; i<snake.size(); i++) {
        if(newHead == snake[i]) return false;
    }

    return true;
}

bool PushFront(pair<int, int> newHead) {
    if(!IsTwisted(newHead)) return false;

    snake.insert(snake.begin(), newHead);

    return true;
}

bool Move(int x, int y) {
    // 사과 유무
    if(apple[x][y]) {
        apple[x][y] = false;

        if(!PushFront(make_pair(x, y))) return false;
    }
    else {
        snake.pop_back();

        if(!PushFront(make_pair(x, y))) return false;
    }

    return true;
}

bool Simulate(int dir, int num) {

    while(num--) {
        ans++;
        
        pair<int, int> snake_head = snake.front();
        int nx = snake_head.first + dx[dir];
        int ny = snake_head.second + dy[dir];

        if(!InRange(nx, ny)) return false;

        if(!Move(nx, ny)) return false;
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m>>k;

    snake.push_back(make_pair(0, 0));
    int x, y;
    for(int i=0; i<m; i++) {
        cin >> x>>y;
        apple[x-1][y-1] = 1;
    }

    mapper['U'] = 0;
    mapper['D'] = 1;
    mapper['R'] = 2;
    mapper['L'] = 3;

    char d;
    int p;
    for(int i=0; i<k; i++) {
        cin >> d>>p;

        if(!Simulate(mapper[d], p))
            break;
    }

    cout << ans;
    return 0;
}