#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> line[10];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int a, b;
    for(int i=0; i<n; i++) {
        cin >>a>>b;
        line[i] = make_pair(a, b);
    }

    int cnt = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                int arr[101] = {};
                
                bool possible = true;
                for(int l=0; l<n; l++) {
                    if(l==i || l==j || l==k) continue;
                    a = line[l].first;
                    b = line[l].second;

                    for(int x=a; x<=b; x++) {
                        if(arr[x] == 1) {
                            possible = false;
                            break;
                        }
                        arr[x] = 1;
                    }

                    if(!possible) break;
                }

                if(possible) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}