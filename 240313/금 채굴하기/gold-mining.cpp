#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n, m;
int arr[MAX_N][MAX_N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    int k = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 1) {
                ans = 1;
                k++;
                break;
            }
        }
        if(k > 0) break;
    }

    if(k == n) {
        cout << ans;
        return 0;
    }


    while(true) {
        int max_cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int cnt = 0;
                // 마름모 날개에 있는 금 개수 확인
                for(int l=0; l<4; l++) {
                    int nx = i+dx[l]*k, ny = j+dy[l]*k;
                    if(!InRange(nx, ny)) continue;

                    if(arr[nx][ny] == 1) cnt++;
                }

                if(k > 1) {
                    int nx = i-(k-1), ny = j-(k-1);
                    for(int a=nx; a<=nx+k; a++) {
                        for(int b=ny; b<=ny+k; b++) {
                            if(!InRange(a, b)) continue;

                            if(arr[a][b] == 1) cnt++;
                        }
                    }
                } else {
                    if(arr[i][j] == 1) cnt++;
                }

                max_cnt = max(max_cnt, cnt);
            }
        }
        // cout << max_cnt << ' ' << (k*k + (k+1)*(k+1)) << '\n';
        if(max_cnt*m > (k*k + (k+1)*(k+1)))
            ans = max(ans, max_cnt);
        else
            break;

        k++;
    }

    cout << ans;
    return 0;
}