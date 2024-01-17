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

    // check[p] = k;
    infect_dev[p] = 1;
    for(int i=0; i<t; i++) {
        tie(tx, x, y) = shack[i];
        // cout << tx << ' ' << x << ' ' << y << '\n'; 
        
        if(infect_dev[x] == 1) check[x]++;
        if(infect_dev[y] == 1) check[y]++;

        //감염됐을 때 횟수를 추가하여 비교하는 것 보다 몇 번 악수를 했는지 확인하는 것이 더 간편함
        if(check[x] <= k && infect_dev[x] == 1) infect_dev[y] = 1;
        if(check[y] <= k && infect_dev[y] == 1) infect_dev[x] = 1;

        // if(infect_dev[x] == 1 && check[x] != 0 && infect_dev[y] == 1 && check[y] != 0){
        //     check[x]--;
        //     check[y]--;
        // }else if(infect_dev[x] == 1 && check[x] != 0) {
        //     infect_dev[y] = 1;
        //     check[y] = k;
        //     check[x]--;
        // } else if (infect_dev[y] == 1 && check[y] != 0) {
        //     infect_dev[x] = 1;
        //     check[x] = k;
        //     check[y]--;
        // }
    }

    for(int i=1; i<=n; i++) {
        cout << infect_dev[i];
    }
    return 0;
}