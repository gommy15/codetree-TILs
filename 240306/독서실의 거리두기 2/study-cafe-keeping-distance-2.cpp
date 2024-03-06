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
    int last_seat = 0;
    for(int i=0; i<n; i++) {
        if(seats[i] == 1) {
            last_seat = i;
            for(int j=i+1; j<n; j++) {
                if(seats[j] == 1) {
                    min_len = min(min_len, (j-i));
                }
            }
        }
    }

    if(seats[n-1] == 0) {
        seats[(x+y)/2] = 0;
        seats[n-1] = 1;
        int min_len2 = INT_MAX;
        for(int i=0; i<n; i++) {
           if(seats[i] == 1) {
                for(int j=i+1; j<n; j++) {
                   if(seats[j] == 1) {
                        min_len2 = min(min_len2, (j-i));
                    }
                }
            }
        }
        min_len = max(min_len, min_len2);   
    }

    cout << min_len;
    return 0;
}