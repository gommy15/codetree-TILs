#include <iostream>
using namespace std;
#define MAX_N 100
#define DIR_NUM 4

int n;

int curr_x, curr_y, curr_dir;
char a[MAX_N+1][MAX_N+1];

// 동일한 위치에 동일한 방향으로 진행했던 적 있는지 확인하는 배열
// 미로 탈출 가능 여부를 확인하기 위해 사용
bool visited[MAX_N+1][MAX_N+1][DIR_NUM];
int elapsed_time;

bool InRange(int x, int y) {
    return 1<=x && x<=n && 1<=y && y<=n;
}

bool WallExist(int x, int y) {
    return InRange(x, y) && a[x][y] == '#';
}

void Simulate() {
    // 현재 위치에서 같은 방향으로 진행한 적이 이미 있는지 확인
    // 한번 경험한 상황이라면 탈출 불가 의미 -> -1 출력하고 종료
    if(visited[curr_x][curr_y][curr_dir]) {
        cout << -1;
        exit(0);
    }

    // 현재 상황이 나중에 반복되는지 확인하기 위해 기록
    visited[curr_x][curr_y][curr_dir] = true;

    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    int next_x = curr_x+dx[curr_dir];
    int next_y = curr_y+dy[curr_dir];

    // 1. 바라보고 있는 방향으로 이동이 불가능하면 반시계방향으로 90도 회전
    if(WallExist(next_x, next_y)) {
        curr_dir = (curr_dir-1+4)%4;
    }

    // 2. 바라보고 있는 방향으로 이동이 가능하다면
    // 2-1. 바로 앞이 격자 밖이면 탈출

    else if (!InRange(next_x, next_y)) {
        curr_x = next_x;
        curr_y = next_y;
        elapsed_time++;
    }

    // 격자 안에서 이동할 수 있는 곳이라면
    else {
        // 현재 진행방향의 오른쪽에 벽이 있는지 확인
        int rx = next_x+dx[(curr_dir+1)%4];
        int ry = next_y+dy[(curr_dir+1)%4];

        // 2-2. 그대로 이동해도 오른쪽에 벽이 있다면 해당방향으로 이동
        if(WallExist(rx, ry)) {
            curr_x = next_x;
            curr_y = next_y;
            elapsed_time++;
        }

        // 2-3. 오른쪽에 벽이 없다면 2칸 이동 후 시계방향으로 90도 회전
        else {
            curr_x = rx;
            curr_y = ry;
            curr_dir = (curr_dir+1)%4;
            elapsed_time += 2;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    cin >> curr_x>>curr_y;
    
    // 주어진 조건에 따라 오른쪽 방향을 바라보며 시작
    curr_dir = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    do {
        Simulate();
    } while(InRange(curr_x, curr_y));

    cout << elapsed_time;
    return 0;
}