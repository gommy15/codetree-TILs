#include <iostream>
#include <string>
using namespace std;

int n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int x=0, y=0, dir_num = 0;;

int main() {
    // 여기에 코드를 작성해주세요.
    string dir;
    cin >> dir;

    int sec = 0;
    bool exist = false;
    for(int i=0; i<dir.size(); i++) {
        sec++;

        if(dir[i] == 'L') dir_num = (dir_num -1 +4)%4;
        else if(dir[i] == 'R') dir_num = (dir_num+1)%4;
        else if (dir[i] == 'F') {
            x += dx[dir_num];
            y += dy[dir_num];

            // if(x ==0 && y == 0) {
            //     exist = true;
            //     break;
            // }
        }

        // 첫번째 문자가 항상 'F'로 주어진다고 가정한다면
        if(x == 0 && y == 0) {
            cout << i+1;
            exist = true;
            break;
        }
    }

    if(!exist) cout << -1;


    // if(exist) cout << sec;
    // else cout << -1;
    return 0;
}