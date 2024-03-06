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

    // 주어진 숫자가 연속한 경우
    if((arr[1]-arr[0]) == 1 && (arr[2]-arr[1]) == 1) cout << 0;
    // 숫자간 간격이 2정도 떨어진 그룹이 있는 경우
    else if((arr[1]-arr[0]) == 2 || (arr[2]-arr[1]) == 2) cout << 1;
    // 숫자간 간격이 모두 3이상 떨어진 경우
    else cout << 2;
    
    return 0;
}