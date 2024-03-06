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

    if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) {
        cout << 0;
        return 0;
    }

    // 최대 이동 횟수는 가운데 사람과 가장 멀리 떨어져 있는 쪽으로 이동하는 경우이며
    // 오른쪽이 멀다면 (오른쪽 끝 사람과 가운데 사람과의 거리) - 1이고
    // 왼쪽이 멀다면 (왼쪽 끝 사람과 가운데 사람과의 거리) -1 이다.
    int move;
    if((arr[1]-arr[0]) > (arr[2]-arr[1])) {
        move = arr[1]-arr[0]-1;
    } else {
        move = arr[2]-arr[1]-1;
    }

    cout << move;

    // 시초과 코드
    // if((arr[1]-arr[0]) > (arr[2]-arr[1])) {
    //     while(true) {
    //         if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) break;
    //         arr[2] = arr[1]-1;
    //         cnt++;
    //         sort(arr, arr+3);
    //     }
    // } else {
    //     while(true) {
    //         if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) break;
    //         arr[0] = arr[1]+1;
    //         cnt++;
    //         sort(arr, arr+3);
    //     }
    // }

    // cout << cnt;
    return 0;
}