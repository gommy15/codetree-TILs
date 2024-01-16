#include <iostream>
using namespace std;
#define OFFSET 100

int n, x1, x2, y1, y2;
int arr[OFFSET*2+1][OFFSET*2+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    bool red = true;
    for(int i=0; i<n; i++) {
        cin >>x1>>y1>>x2>>y2;

        x1+=OFFSET;
        x2+=OFFSET;
        y1+=OFFSET;
        y2+=OFFSET;

        for(int j=x1; j<x2; j++) {
            for(int k=y1; k<y2; k++) {
                if(red) arr[j][k] = 1;
                else arr[j][k] = 2;
            }
        }

        if(red) red = false;
        else red = true;
    }

    int cnt=0;
    for(int i=0; i<OFFSET*2+1; i++) {
        for(int j=0; j<OFFSET*2+1; j++) {
            if(arr[i][j] == 2) cnt++;
        }
    }

    cout << cnt;
    return 0;
}