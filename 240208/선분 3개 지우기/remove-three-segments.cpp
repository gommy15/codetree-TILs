#include <iostream>
using namespace std;
#define MAX_N 10
#define MAX_AB 100

int n;
int a[MAX_N], b[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    int cnt = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                int tmp[MAX_AB+1] = {};
                bool mLine = false;
                for(int l=0; l<n; l++) {
                    if(l==i || l==j || l==k) continue;

                    for(int x=a[l]; x<=b[l]; x++) {
                        if(tmp[x] != 0) {
                            mLine = true;
                            break;
                        }
                        tmp[x]++;
                    }

                    if(mLine) break;
                }
                if(!mLine) cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}