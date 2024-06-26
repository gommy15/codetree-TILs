#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 10

int n;
int grid[MAX_N][MAX_N];

bool visited[MAX_N];
// vector<pair<int, int>> selected_pos;
int ans = 0;

// int Calc() {
//     int x, y;
//     int sum = 0;
//     for(int i=0; i<selected_pos.size(); i++) {
//         tie(x, y) = selected_pos[i];
//         sum += grid[x][y];
//     }

//     return sum;
// }

void FindMaxNum(int row, int sum) {
    if(row == n) {
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        FindMaxNum(row+1, sum + grid[row][i]);
        visited[i] = false;
    }

    // for(int i=0; i<n; i++) {
    //     if(vx[i]) continue;
    //     for(int j=0; j<n; j++) {
    //         if(vy[j]) continue;

    //         selected_pos.push_back(make_pair(i, j));
    //         vx[i] = vy[j] = true;
    //         FindMaxNum(cnt+1);
    //         selected_pos.pop_back();
    //         vx[i] = vy[j] = false;
    //     }
    // }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    FindMaxNum(0, 0);

    cout << ans;
    return 0;
}