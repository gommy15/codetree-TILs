#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, m;
int grid[MAX_N][MAX_N];

int seq[MAX_N];

bool IsHappySequence() {
    int cnt = 1, max_cnt = 1;

    for(int i=1; i<n; i++) {
        if(seq[i-1] == seq[i]) {
            cnt++;
        } else {
            cnt = 1;
        }

        max_cnt = max(max_cnt, cnt);
    }

    return max_cnt >= m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int num_happy = 0;

    // 가로 확인
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            seq[j] = grid[i][j];
        }

        if(IsHappySequence()) {
            num_happy++;
        }
    }

    //세로 확인
    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            seq[i] = grid[i][j];
        }

        if(IsHappySequence()) {
            num_happy++;
        }
    }


    cout << num_happy;
    return 0;
}