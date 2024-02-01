#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int n;
int arr[MAX_N][MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int max_cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-2; j++) {
            for(int k=0; k<n; k++) {
                for(int l=0; l<n-2; l++) {
                    // 1*3 격자가 같은 줄에 있고 겹치는 부분이 있다면 그냥 넘어가기
                    if(i==k && abs(j-l) <= 2) continue;

                    int cnt = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[k][l] + arr[k][l+1] + arr[k][l+2];
                    max_cnt = max(max_cnt, cnt);
                }
            }
        }
    }

    cout << max_cnt;
    return 0;
}