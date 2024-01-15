#include <iostream>
using namespace std;

int arr[1000];
int n, x;
char dir;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int dir_num, now = 500;
    int max_spot = 0, min_spot = 1000;
    for(int i=0; i<n; i++) {
        cin >> x>>dir;
        if(dir == 'L') dir_num = -1;
        else if (dir == 'R') dir_num = 1;

        for(int i=0; i<x; i++) {
            now += dir_num;
            arr[now] += 1;
        }
        max_spot = max(max_spot, now);
        min_spot = min(min_spot, now);

    }

    int cnt = 0;
    for(int i = min_spot; i<=max_spot; i++) {
        if(arr[i] >= 2) cnt++;
    }

    cout << cnt;
    return 0;
}