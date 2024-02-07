#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_N 100

int n;
int x1[MAX_N], x2[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        bool exist = false;
        for(int j=0; j<n; j++) {
            if(i==j) continue;

            if((x1[j] <= x1[i] && x2[j] >= x2[i]) || (x1[j] >= x1[i] && x2[j] <= x2[i])) {
                exist = true;
                break;
            }
        }
        if(!exist) cnt++;
    }

    cout << cnt;
    return 0;
}