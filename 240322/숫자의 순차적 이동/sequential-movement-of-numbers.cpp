#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

#define MAX_N 20
#define DIR_NUM 8

int n, m;
int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

pair<int, int> FindPos(int num) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == num)
                return make_pair(i, j);
        }
    }
}

pair<int, int> NestPos(pair<int, int> pos) {
    int dx[DIR_NUM] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[DIR_NUM] = { -1, 0,  1, -1, 1, -1, 0, 1};

    int x, y;
    tie(x, y) = pos;

    int max_num = -1;
    pair<int, int> max_pos;
    for(int i=0; i<DIR_NUM; i++) {
        int nx = x+dx[i], ny=y+dy[i];
        if(InRange(nx, ny) && grid[nx][ny] > max_num) {
            max_num = grid[nx][ny];
            max_pos = make_pair(nx, ny);
        }
    }

    return max_pos;
}

void Swap(pair<int, int> pos, pair<int, int> next_pos) {
    int x, y, nx, ny;
    tie(x, y) = pos;
    tie(nx, ny) = next_pos;

    int tmp = grid[x][y];
    grid[x][y] = grid[nx][ny];
    grid[nx][ny] = tmp;
}

void Simulate() {
    for(int num=1; num<=n*n; num++) {
        pair<int, int> pos = FindPos(num);
        pair<int, int> next_pos = NestPos(pos);
        Swap(pos, next_pos);
    }
}

int main() {
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    while(m--) {
        Simulate();
    }

    for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << '\n';
	}
}


// #include <iostream>
// #include <utility>
// #define MAX_N 20
// #define DIR_NUM 8
// using namespace std;

// int n, m;
// int grid[MAX_N][MAX_N];
// pair<int, int> pos[MAX_N+1];
// int count[MAX_N*MAX_N+1];

// bool InRange(int x, int y) {
//     return 0<=x && x<n && 0<=y && y<n;
// }

// void Move(int target) {
//     int dx[DIR_NUM] = {0, -1, -1, -1, 0, 1, 1, 1};
//     int dy[DIR_NUM] = {1, 1, 0, -1, -1, -1, 0, 1};

//     int max_num = target;
//     int x = pos[target].first, y = pos[target].second;
//     int ch_x, ch_y;
//     for(int i=0; i<DIR_NUM; i++) {
//         int nx = x+dx[i], ny = y+dy[i];
//         if(InRange(nx, ny) && grid[nx][ny] > max_num) {
//             max_num = grid[nx][ny];
//             ch_x = nx; ch_y = ny;
//         }
//     }
    
//     if(max_num != target) {
//         grid[ch_x][ch_y] = grid[x][y];
//         grid[x][y] = max_num;

//         pos[target] = make_pair(ch_x, ch_y);
//         pos[max_num] = make_pair(x, y);
//     }

//     // cout << target << '\n';
//     // for(int i=0; i<n; i++) {
//     //     for(int j=0; j<n; j++) {
//     //         cout << grid[i][j] << ' ';
//     //     }
//     //     cout << '\n';
//     // }
//     // cout << '\n';

// }

// void Simulate() {
//     for(int i=1; i<=n*n; i++) {
//         Move(i);
//     }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n>>m;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> grid[i][j];
//             pos[grid[i][j]] = make_pair(i, j);
//         }
//     }

//     while(m--) {
//         Simulate();
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }