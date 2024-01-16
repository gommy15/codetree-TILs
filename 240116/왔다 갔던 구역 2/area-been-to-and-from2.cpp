#include <iostream>
using namespace std;
#define OFFSET 1000
#define MAX_N 100
#define MAX_R 2000

int n, x;
char dir;
int x1[MAX_N], x2[MAX_N], checked[MAX_R+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int dir_num, now = 0;

    for(int i=0; i<n; i++) {
        cin >> x>>dir;
        if(dir == 'L') dir_num = -1;
        else if (dir == 'R') dir_num = 1;

        int a = now + x*dir_num;
        if(a > now) {
            x1[i] = now;
            x2[i] = a;
        } else {
            x1[i] = a;
            x2[i] = now;
        }

        now += x*dir_num;
        x1[i] += OFFSET;
        x2[i] += OFFSET;
    }

    for(int i=0; i<n; i++) {
        for(int j=x1[i]; j<x2[i]; j++) {
            checked[j]++;
        }
    }

    int cnt = 0;
    for(int i = 0; i<=MAX_R; i++) {
        if(checked[i] >= 2) cnt++;
    }

    cout << cnt;
    return 0;
}