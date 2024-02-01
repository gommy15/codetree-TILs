#include <iostream>
using namespace std;
#define MAX_NM 100

int n, m;
int arr_a[MAX_NM], arr_b[MAX_NM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;
    for(int i=0; i<n; i++) {
        cin >> arr_a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> arr_b[i];
    }

    int cnt = 0;

    for(int i=0; i<=n-m; i++) {
        int num = 0;
        for(int j=i; j<i+m; j++) {
            bool exist = false;
            for(int k=0; k<m; k++) {
                if(arr_a[j] == arr_b[k]) exist = true;
            }
            if(!exist) break;
            else num++;
        }
        if(num == m) cnt++;
    }

    cout << cnt;
    return 0;
}