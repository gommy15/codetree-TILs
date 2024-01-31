#include <iostream>
using namespace std;

int arr[19][19];
// 대각선까지 생각하기!!
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            cin >> arr[i][j];
        }
    }

    int winner = 0;
    int mid_x, mid_y;
    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            if(arr[i][j] != 0) {
                for(int k=0; k<8; k++) {
                    int x = i+dx[k], y = j+dy[k];
                    if(arr[i][j] == arr[x][y]) {
                        int cnt = 2;
                        int m_x, m_y;
                        while(cnt != 5) {
                            x += dx[k];
                            y += dy[k];

                            if(arr[i][j] != arr[x][y]) break;
                            cnt++;
                            if(cnt == 3) {
                                m_x = x+1;
                                m_y = y+1;
                            }
                        }

                        if(cnt == 5) {
                            winner = arr[i][j];
                            mid_x = m_x;
                            mid_y = m_y;

                        } 
                    }
                }
            }
        }
    }

    cout << winner << '\n';
    cout << mid_x << ' ' << mid_y;
    return 0;
}