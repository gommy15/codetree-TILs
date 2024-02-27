#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int n, k;
int arr[MAX_N];

bool IsPossible(int limit) {
    int pre_idx = 0;

    for(int i=1; i<n; i++) {
        if(arr[i] <= limit){
            // 건너뛰기 하는 크기가 k 보다 크면 불가능한 최대값이다.
            if(i - pre_idx > k) return false;
            pre_idx = i;
        }
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // 첫번째 값과 마지막 값 중 큰 값을 기준으로 가정하는 최대값을 1씩 늘려간다.
    for(int i=max(arr[0], arr[n-1]); i<=MAX_N; i++) {
        // 가능한 최대값 중 최소값을 구하는 것이므로 한계값을 1씩 늘려가면서 찾되 가능한 가짓수가 나오는 경우 바로 가짓수 찾기를 종료한다.
        if(IsPossible(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}