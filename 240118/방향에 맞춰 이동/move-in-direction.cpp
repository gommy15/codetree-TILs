#include <iostream>
using namespace std;
#define MAX_LEN 1000

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int n, nx=0, ny=0;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    char dir;
    int len;
    for(int i=0; i<n; i++) {
        cin >> dir>>len;
        int dir_idx;

        if(dir == 'W') dir_idx = 0;
        else if (dir == 'S') dir_idx = 1;
        else if (dir == 'N') dir_idx = 2;
        else if (dir == 'E') dir_idx = 3;

        nx = nx + (len * dx[dir_idx]);
        ny = ny + (len * dy[dir_idx]);
    }

    cout << nx << ' ' << ny;
    return 0;
}