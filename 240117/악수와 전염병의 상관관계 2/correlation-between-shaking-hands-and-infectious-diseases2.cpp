#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 100
#define MAX_T 250

int n, k, p, t, tx, x, y;
int infect_dev[MAX_N+1];
int check[MAX_N+1];
tuple<int, int, int> shack[MAX_T];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k>>p>>t;

    for(int i=0; i<t; i++) {
        cin >>tx>>x>>y;
        shack[i] = make_tuple(tx, x, y);
    }

    sort(shack, shack+t);

    check[p] = k;
    infect_dev[p] = 1;
    for(int i=0; i<t; i++) {
        tie(tx, x, y) = shack[i];
        if(infect_dev[x] == 1 && check[x] != 0 && infect_dev[y] == 1 && check[y] != 0){
            check[x]--;
            check[y]--;
        }else if(infect_dev[x] == 1 && check[x] != 0) {
            infect_dev[y] = 1;
            check[y] = k;
            check[x]--;
        } else if (infect_dev[y] == 1 && check[y] != 0) {
            infect_dev[x] = 1;
            check[x] = k;
            check[y]--;
        }
    }

    for(int i=1; i<=n; i++) {
        cout << infect_dev[i];
    }
    return 0;
}