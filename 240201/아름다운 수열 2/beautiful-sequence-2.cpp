#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100

int n, m;
int arr_a[MAX_NM], arr_b[MAX_NM], tmp[MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr_a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> arr_b[i];
    }

    // sort를 하면 아름다운 수열을 정렬하여 쉽게 확인할 수 있다.
    sort(arr_b, arr_b+m);
    int cnt = 0;

    for(int i=0; i<=n-m; i++) {
        //임의의 배열을 두어 섞이지 않고 배열을 비교할 수 있도록 한다.
        for(int j=0; j<m; j++) {
            tmp[j] = arr_a[i+j];
        }

        sort(tmp, tmp+m);

        bool same = true;
        for(int j=0; j<m; j++) {
            if(tmp[j] != arr_b[j]) {
                same = false;
                break;
            }
        }
        if(same) cnt++;
    }

    cout << cnt;
    return 0;
}