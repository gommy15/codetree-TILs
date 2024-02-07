#include <iostream>
using namespace std;
#define MAX_N 20
#define MAX_K 10

int k, n;
int ranking[MAX_K][MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;
    int dev;
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            cin >> dev;
            ranking[i][dev] = j+1; 
        }
    }

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;

            bool exist = true;
            for(int x=0; x<k; x++) {
                if(ranking[x][i] > ranking[x][j]) exist = false;
            }

            if(exist) cnt++;
        }
    }

    cout << cnt;
    return 0;
}