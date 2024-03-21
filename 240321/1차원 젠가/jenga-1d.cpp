#include <iostream>
#include <iterator>
using namespace std;
#define MAX_N 100

int n;
int arr[MAX_N+1];

int DropBlock(int s, int e) {
    int cnt = 1;
    int tmp[MAX_N+1] = {};
    for(int i=1; i<=n; i++) {
        if(s <= i && i <= e) 
            continue;
        tmp[cnt++] = arr[i];
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        arr[i] = tmp[i];
        if(arr[i] > 0) ans++;
    }
    return ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int s1, e1;
    cin >> s1>>e1;
    int ans = DropBlock(s1, e1);

    int s2, e2;
    cin >> s2>>e2;
    ans = DropBlock(s2, e2);

    cout << ans << '\n';

    for(int i=1; i<=n; i++) {
        if(arr[i] == 0) break;
        cout << arr[i] << '\n';
    }
    
    return 0;
}