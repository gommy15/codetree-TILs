#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);

    int cnt = 0;
    if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) {
        cout << 0;
        return 0;
    }
    if((arr[1]-arr[0]) > (arr[2]-arr[1])) {
        while(true) {
            if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) break;
            arr[2] = arr[1]-1;
            cnt++;
            sort(arr, arr+3);
        }
    } else {
        while(true) {
            if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) break;
            arr[0] = arr[1]+1;
            cnt++;
            sort(arr, arr+3);
        }
    }

    cout << cnt;
    return 0;
}