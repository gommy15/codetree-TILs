#include <iostream>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // 뒤에서부터 보면서 정렬되어있지 않은 순간을 잡아 그 앞에 있는 원소들을 전부 옮기면 됨

    int idx = n-2;
    while(idx >= 0 && arr[idx] < arr[idx+1]) {
        idx--;
    }

    cout << idx+1;
    return 0;
}