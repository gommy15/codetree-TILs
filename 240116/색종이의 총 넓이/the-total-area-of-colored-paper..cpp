#include <iostream>
using namespace std;
#define LEN 8
#define OFFSET 100

int n, x, y;
int arr[OFFSET*2+1][OFFSET*2+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x>>y;
        x+=OFFSET;
        y+=OFFSET;

        for(int j=x; j<x+LEN; j++) {
            for(int k=y; k<y+LEN; k++) {
                arr[j][k] = 1;
            }
        }
    }

    int cnt=0;
    for(int i=0; i<OFFSET*2+1; i++) {
        for(int j=0; j<OFFSET*2+1; j++) {
            if(arr[i][j] == 1) cnt++;
        }
    }

    cout << cnt;
    return 0;
}