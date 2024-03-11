#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char arr[10][10];
string ln;

int main() {
    // 여기에 코드를 작성해주세요.
    int bx, by, rx, ry, lx, ly;
    for(int i=0; i<10; i++) {
        cin >> ln;
        for(int j=0; j<10; j++) {
            arr[i][j] = ln[j];
            if(ln[j] == 'B') {
                bx = i;
                by = j;
            } else if (ln[j] == 'R') {
                rx = i;
                ry = j;
            } else if (ln[j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }

    cout << abs(lx-bx) + abs(ly-by)-1;
    return 0;
}