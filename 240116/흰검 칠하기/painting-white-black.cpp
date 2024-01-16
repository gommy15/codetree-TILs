#include <iostream>
using namespace std;
#define MAX_AR 200000
#define OFFSET 100000

int n, x;
char dir;
int black[MAX_AR+1], white[MAX_AR+1], arr[MAX_AR+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int now = OFFSET;
    for(int i=0; i<n; i++) {
        cin >> x>>dir;

        // if(dir == 'L') {
        //     while(x--) {
        //         arr[now] = 1;
        //         white[now]++;
        //         if(x) now--;
        //     }
        // }
        // else {
        //     // x칸 오른쪽으로 칠합니다.
        //     while(x--) {
        //         arr[now] = 2;
        //         black[now]++;
        //         if(x) now++;
        //     }
        // }

        if(dir == 'L') {
            for(int j = now; j>now-x; j--) {
                white[j]++;
                arr[j] = 1;
            }
            now -= (x-1);
        } else if (dir == 'R') {
            for(int j=now; j<now+x; j++) {
                black[j]++;
                arr[j] = 2;
            }
            now += (x-1);
        }

        // for(int j=OFFSET-7; j<=OFFSET+7; j++) {
        //     cout << white[j] << ' ';
        // }
        // cout << '\n';
        // for(int j=OFFSET-7; j<=OFFSET+7; j++) {
        //     cout << black[j] << ' ';
        // }
        // cout << '\n';
        // for(int j=OFFSET-7; j<=OFFSET+7; j++) {
        //     cout << arr[j] << ' ';
        // }
        // cout << '\n';
        // cout << '\n';
    }

    int bl_num=0, wh_num=0, gr_num=0;
    for(int i=0; i<=MAX_AR; i++) {
        if(black[i] >= 2 && white[i] >=2) gr_num++;
        else if(arr[i] == 1) wh_num++;
        else if(arr[i] == 2) bl_num++; 
    }

    cout << wh_num << ' ' << bl_num << ' ' << gr_num;
    return 0;
}