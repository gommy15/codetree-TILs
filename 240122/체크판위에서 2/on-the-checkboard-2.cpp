#include <iostream>
using namespace std;
#define MAX_RC 15

char arr[MAX_RC][MAX_RC];
int r, c;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    for(int i=1; i<r; i++) {
        for(int j=1; j<c; j++) {
            if(arr[i][j] != arr[0][0]) {
                for(int k=i+1; k<r-1; k++) {
                    for(int l=j+1; l<c-1; l++) {
                        if(arr[k][l] != arr[i][j] && arr[k][l] != arr[r-1][c-1]) cnt++;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}