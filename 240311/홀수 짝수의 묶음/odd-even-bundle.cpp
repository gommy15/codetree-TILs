#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n;
int arr[MAX_N];
int odd, even;

int main() {
    // 짝수와 홀수의 조합만 잘 하면 될 뿐 어떤 숫자로 조합되었는지는 상관이 없다.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) even++;
        else odd++;
    }

    // group_num이 짝수일 때, 묶음이 짝수로 나와야하고
    // group_num이 홀수일 때, 묶음이 홀수로 나와야 함
    int group_num = 0;
    while(true) {
        if(group_num%2 == 0) {
            if(even) {
                even--;
                group_num++;
            } else if (odd >= 2) {
                odd -= 2;
                group_num++;
            } else {
                //숫자는 남았지만 더이상 그룹을 만들지 못하는 상황 -> 그룹의 개수를 1개 줄이는 것이 최선
                if(odd > 0 || even > 0) {
                    group_num--;
                }

                break;
            }
        }
        else {
            if(odd) {
                odd--;
                group_num++;
            } else {
                // 짝수로만 홀수 그룹을 만들지 못함
                // 남은 짝수를 아무 곳에나 넣어도 홀짝에 영향을 미치지 못함
                break;
            }
        }
    }

    cout << group_num;
    return 0;
}