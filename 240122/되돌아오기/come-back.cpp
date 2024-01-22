#include <iostream>
using namespace std;

int n;
int dx[4] = {1, -1,  0, 0}, dy[4] = {0,  0, -1, 1};
char dir;
int t;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int x=0, y=0, sec = 0;
    bool exist = false;
    for(int i=0; i<n; i++) {
        cin >>dir>>t;

        int dir_num;
        if(dir == 'E') dir_num = 0;
        else if (dir == 'W') dir_num = 1;
        else if (dir == 'S') dir_num = 2;
        else if (dir == 'N') dir_num = 3;

        while(t--) {
            x += dx[dir_num];
            y += dy[dir_num];

            sec++;
            if(x == 0 && y == 0) {
                exist = true;
                break;
            }
        }

        if(exist) break;
    }

    if(exist) cout << sec;
    else cout << -1;
    
    return 0;
}