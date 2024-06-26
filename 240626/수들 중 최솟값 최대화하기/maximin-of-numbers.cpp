#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX_N 10

int n;
bool visited[MAX_N+1];
int grid[MAX_N][MAX_N];
int ans = 0;

void FindMaxMin(int row, int min_num) {
    if(row == n) {
        ans = max(ans, min_num);
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        FindMaxMin(row+1, min(min_num, grid[row][i]));
        visited[i] = false;
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    FindMaxMin(0, INT_MAX);

    cout << ans;
    return 0;
}