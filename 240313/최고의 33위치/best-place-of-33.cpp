#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N   20

int n;
int arr[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0<=x && x<n && 0<=y && y<n;
}

int FindCnt(int x, int y) {
    int cnt = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(!InRange(x+i, y+j)) return 0;

            if(arr[x+i][y+j] == 1) cnt++;
        }
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int max_cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            max_cnt = max(max_cnt, FindCnt(i, j));
        }
    }

    cout << max_cnt;
    return 0;
}