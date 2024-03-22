// 영향을 받는 칸의 위치는 폭탄이 터진 위치와 행과 열 중 하나가 꼭 일치해야 함
// 여기서 거리는 행 간의 차와 열 간의 차의 합으로 나타낼 수 있는 맨하탄 거리임
// (|x1-x2| + |y1-y2|)

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200

int n;
int grid[MAX_N][MAX_N];

// 중요!!!
bool InBombRange(int x, int y, int center_x, int center_y, int bumb_range) {
    return (x == center_x || y == center_y) && abs(x-center_x) + abs(y-center_y) < bumb_range;
}

void Gravity() {
    int tmp[MAX_N][MAX_N] = {};

    for(int col = 0; col<n; col++) {
        int cnt = n-1;
        for(int row = n-1; row>=0; row--) {
            if(grid[row][col] == 0) continue;
            tmp[cnt--][col] = grid[row][col];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

void Bumb(int center_x, int center_y) {
    int bumb_range = grid[center_x][center_y];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(InBombRange(i, j, center_x, center_y, bumb_range)) grid[i][j] = 0;
        }
    }

    Gravity();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r>>c;

    Bumb(r-1, c-1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }

        cout << '\n';
    }
    return 0;
}