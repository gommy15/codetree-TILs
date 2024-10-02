#include <iostream>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N+1], result[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int arr_size = n;
    for(int k=0; k<2; k++) {
        int s, e;
        cin >> s>>e;

        int cnt = 1;
        for(int i=1; i<=arr_size; i++) {
            if(s <= i && i <= e) continue;
            result[cnt++] = arr[i];
            // cnt++;
        }

        for(int i=1; i<=arr_size; i++) {
            arr[i] = result[i];
        }

        arr_size = cnt-1;

        // for(int i=1; i<=arr_size; i++) {
        //     cout << arr[i] << '\n';
        // }
        // cout << '\n';
    }

    cout << arr_size << '\n';
    for(int i=1; i<=arr_size; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}