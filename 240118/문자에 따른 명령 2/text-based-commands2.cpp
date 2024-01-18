#include <iostream>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int main() {
    // 여기에 코드를 작성해주세요.
    string dir;
    int nx = 0, ny = 0;
    int dir_num = 3;

    cin >> dir;
    for(int i=0; i<dir.size(); i++) {
        // cout << dir[i] << '\n';
        if(dir[i] == 'L') {
            dir_num = (dir_num-1+4)%4;
        } else if (dir[i] == 'R') {
            dir_num = (dir_num+1)%4;
        } else if (dir[i] == 'F') {
            nx += dx[dir_num];
            ny += dy[dir_num];
        }
        // cout << nx << ' ' << ny << '\n';
    }

    cout << nx << ' ' << ny;
    return 0;
}