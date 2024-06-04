#include <iostream>
using namespace std;
#define MAX_N 100

int n, m, ans;
int bombs[MAX_N];

int CheckBombs(int x) {
    int cnt = 1;
    for(int i=x+1; i<n; i++) {
        if(bombs[x] != bombs[i]) break;

        cnt++;
    }

    return cnt;
}

void DeleteBumbs(int x, int cnt) {
    for(int i=x; i<x+cnt; i++) {
        bombs[i] = 0;
    }
}

bool Simulate() {
    int exist = false;
    for(int i=0; i<n-1; i++) {
        if(bombs[i] != 0) {
            int nums = CheckBombs(i);
            // cout << nums << '\n';
            if(nums >= m) {
                DeleteBumbs(i, nums);
                exist = true;
            }
        }
    }

    if(!exist) return exist;

    int tmp[MAX_N] = {};
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(bombs[i] != 0)
            tmp[cnt++] = bombs[i];
    }

    for(int i=0; i<n; i++) {
        bombs[i] = tmp[i];
    }

    ans = cnt;
    return true;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m;
    for(int i=0; i<n; i++) {
        cin >> bombs[i];
    }

    ans = n;
    while(Simulate()) {};

    cout << ans << '\n';
    for(int i=0; i<ans; i++) {
        cout << bombs[i] << '\n';
    }
    
    return 0;
}