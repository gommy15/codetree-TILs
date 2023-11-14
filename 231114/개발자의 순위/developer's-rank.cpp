#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int arr[10][20];


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;

            bool correct = true;

            for(int x=0; x<k; x++) {
                int idx_i = 0, idx_j = 0;

                for(int y=0; y<n; y++) {
                    if(arr[x][y] == i) idx_i = y;
                    if(arr[x][y] == j) idx_j = y;
                }

                if(idx_i > idx_j) correct = false;
            }
            
            if(correct) cnt++;
        }
    }

    cout << cnt;
    return 0;
}