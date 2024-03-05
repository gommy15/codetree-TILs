// 간단히 푸는 방법
// 시작점 중 가장 뒤에 있는 좌표와 끝점 중 가장 앞에 있는 점의 좌표가 겹치지 않는다면 전부 겹칠 수 없음
#include <iostream>
#include <algorithm>
using namespace std;

int n, x1, x2;
int max_x1 = 0, min_x2 = 101;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >>x1>>x2;
        max_x1 = max(max_x1, x1);
        min_x2 = min(min_x2, x2);
    }

    if(min_x2 >= max_x1) cout << "Yes";
    else cout << "No";

    return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define MAX_N 100
// #define MAX_X 100

// int n;
// int x1[MAX_N], x2[MAX_N];
// int arr[MAX_X+1];

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n;
//     for(int i=0; i<n; i++) {
//         cin >> x1[i] >> x2[i];
//     }

//     for(int i=0; i<n; i++){
//         for(int j=x1[i]; j<=x2[i]; j++) {
//             arr[j]++;
//         }
//     }

//     int max_over = *max_element(arr, arr+MAX_X+1);

//     if(max_over == n) {
//         cout << "Yes";
//     } else {
//         cout << "No";
//     }
//     return 0;
// }