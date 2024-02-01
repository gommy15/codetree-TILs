#include <iostream>
using namespace std;
#define MAX_NM 50

int n, m;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
char arr[MAX_NM][MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 'L') {
                for(int k=0; k<8; k++) {
                    int x = i+dx[k], y = j+dy[k];
                    if(arr[x][y] == 'E' && arr[x+dx[k]][y+dy[k]] == 'E') cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}