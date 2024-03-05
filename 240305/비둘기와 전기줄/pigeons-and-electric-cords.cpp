#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_PIZON 10

int n;
int arr[MAX_PIZON+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int num, dir;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cin >> num>>dir;
        dir++;
        if(arr[num] == 0) arr[num] = dir;
        else if(arr[num] != dir) {
            cnt++;
            arr[num] = dir;
        }
    }

    cout << cnt;
    return 0;
}