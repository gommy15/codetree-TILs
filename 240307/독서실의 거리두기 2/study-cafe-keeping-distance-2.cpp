#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 1000

int n;
int seats[MAX_N];
string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>str;
    for(int i=0; i<n; i++) {
        seats[i] = str[i] - '0';
    }

    int x=0, y=0;
    
    for(int i=0; i<n; i++) {
        if(seats[i] == 1) {
            for(int j=i+1; j<n; j++) {
                if(seats[j] == 1) {
                    if(j-i > y-x) {
                        x = i;
                        y = j;
                    }

                    break;
                }
            }
        }
    }
    // 예외사항 1 . 맨 앞 좌석이 비어있을 때
    int max_len = -1;
    int max_idx = 0;
    if(seats[0] == 0) {
        int len = 0;
        for(int i=0; i<n; i++) {
            if(seats[i] == 1) break;
            len++;
        }
        if(len > max_len) {
            max_len = len;
            max_idx = 0;
        }
    }

    // 예외사항 2. 맨 뒷 좌석이 비어있을 떄
    if(seats[n-1] == 0) {
        int len = 0;
        for(int i=n-1; i>=0; i--) {
            if(seats[i] == 1) break;
            len++;
        }
        if(len > max_len) {
            max_len = len;
            max_idx = n-1;
        }
    }

    // 최적의 위치에 자리 선정
    if(max_len >= (y-x)/2) {
        seats[max_idx] = 1;
    } else {
        seats[(x+y)/2] = 1;
    }

    int min_len = INT_MAX;
    for(int i=0; i<n; i++) {
        if(seats[i] == 1) {
            for(int j=i+1; j<n; j++) {
                if(seats[j] == 1) {
                    min_len = min(min_len, (j-i));
                    break;
                }
            }
        }
    }

    cout << min_len;
    return 0;
}