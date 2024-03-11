#include <iostream>
using namespace std;
#define MAX_N 100

int n, m;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //사람이 살고 있는 곳이 나오면 와이파이를 m만큼 떨어진 곳에 놓은 뒤 2m 만큼 떨어져서 다시 탐색 진행!
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            cnt++;
            i += 2*m;
        }
    }

    cout << cnt;
    return 0;
}