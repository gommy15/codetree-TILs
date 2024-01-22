#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, r, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int arr[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool Checked(int x, int y) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i], ny = y+dy[i];

        if(InRange(nx, ny) && arr[nx][ny] == 1) cnt++;
    }
    
    if(cnt == 3) return true;
    else return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<m; i++) {
        cin >> r>>c;
        r--; c--;
        
        arr[r][c] = 1;
        bool relex = Checked(r, c);

        if(relex) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}