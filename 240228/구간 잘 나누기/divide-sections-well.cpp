#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100
#define MAX_A 10000

int n, m;
int arr[MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // 1부터 시작하여 최댓값이 될 수 있는 수를 찾아가기
    for(int a=1; a<=MAX_A; a++) {
        int b_cnt = 0;
        int b_sum = 0;
        bool possible = true;
        for(int i=0; i<n; i++) {
            //단일 값이 최댓값 기준을 넘어가면 해당 최댓값은 불가능함
            if(arr[i] > a) {
                possible = false;
                break;
            }

            // 합이 최댓값을 넘어가면 secssion 구분하고 새로운 구간 시작
            if(b_sum + arr[i] > a) {
                b_cnt++;
                b_sum = 0;
            }

            b_sum += arr[i];
        }

        // secssion 개수가 m-1개이고 모든 조건을 만족한 최초의 경우가 정답임
        if(possible && b_cnt == m-1) {
            cout << a;
            break;
        }
    }
    return 0;
}