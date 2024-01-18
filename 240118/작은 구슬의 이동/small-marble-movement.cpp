#include <iostream>
using namespace std;
#define MAX_N 50

int arr[MAX_N][MAX_N];
int n, t, r, c;
char d;

//좌표평면 x, y라고 생각하지 말기!!!!
// 오른쪽으로 가면 열인 y가 증가하고 위로가면 행인 x가 증가한다.
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    cin >> r>>c>>d;
    r--; c--;
    int dir_num;


    if(d == 'U') dir_num = 2;
    else if (d == 'D') dir_num = 1;
    else if (d == 'R') dir_num = 0;
    else if (d == 'L') dir_num = 3;

    
    int nx, ny;
    while(t--) {
        nx = r+dx[dir_num];
        ny = c+dy[dir_num];

        if(!InRange(nx, ny)) {
            dir_num = 3-dir_num;
            // continue;
        }else {
            r = nx;
            c = ny;
        }
    }

    cout << r+1 << ' ' << c+1;
    return 0;
}