// 4방향 모두 구현하는 것은 반복되는 코드가 많아지므로 효율적인 코드가 아님
// 특정 횟수만큼 90도로 회전하여 아래로 떨어질 수 있도록 만든 후
// 다시 원래 방향으로 돌아가도록 특정 횟수만큼 90도로 회전하면 4번의 반복된 코드를 작성하는 것보다
// 효율적으로 코드를 작성할 수 있음

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 4
#define ASCII_NUM 128
#define NONE -1

int n=4;
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];

// grid를 90도 회전
void Rotate() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    // 90도 회전
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = grid[n-j-1][i];
        }
    }

    // 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void Drop() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            next_grid[i][j] = 0;
        }
    }

    for(int j=0; j<n; j++) {
        int keep_num = NONE, next_row = n-1;
        for(int i=n-1; i>=0; i--) {
            if(!grid[i][j]) continue;

            // 아직 내려간 숫자가 없다면 갱신
            if(keep_num == NONE) {
                keep_num = grid[i][j];
            } else if (keep_num == grid[i][j]) {
                // 가장 최근에 관찰한 숫자가 현재 숫자와 일치한다면 하나로 합치고 keep값을 초기화
                next_grid[next_row--][j] = keep_num*2;
                keep_num = NONE;
            } else {
                // 가장 최근에 관찰한 숫자와 현재 숫자가 다르다면 최근 관찰한 숫자를 내리고 keep값 갱신
                next_grid[next_row--][j] = keep_num;
                keep_num = grid[i][j];
            }
        }

        // 전부 다 실행했는데도 keep 값이 남아있다면 마지막으로 떨어뜨림
            if(keep_num != NONE)
                next_grid[next_row--][j] = keep_num;
    }

    // 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }    
}

void Tilt(int move_dir) {
    // 1. move_dir 횟수만큼 시계방향으로 90도로 회전
    // 움직이는 방향이 아래쪽이 되도록 회전!
    for(int i=0; i<move_dir; i++) {
        Rotate();
    }

    // 2. 아래 방향으로 움직임
    Drop();

    // 3. 4-move_dir 횟수만큼 시계방향으로 회전시켜 처음 상태로 복원 (총 360도 회전)
    for(int i=0; i<4-move_dir; i++) {
        Rotate();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    char dir_char;
    cin >> dir_char;
    
    int dir_mapper[ASCII_NUM];
    dir_mapper['D'] = 0;
    dir_mapper['R'] = 1;
    dir_mapper['U'] = 2;
    dir_mapper['L'] = 3;

    Tilt(dir_mapper[dir_char]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}