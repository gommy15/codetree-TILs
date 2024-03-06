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

    seats[(x+y)/2] = 1;
    int min_len = INT_MAX;
    for(int i=0; i<n; i++) {
        if(seats[i] == 1) {
            for(int j=i+1; j<n; j++) {
                if(seats[j] == 1) {
                    min_len = min(min_len, (j-i));
                }
            }
        }
    }

    cout << min_len;
    return 0;
}