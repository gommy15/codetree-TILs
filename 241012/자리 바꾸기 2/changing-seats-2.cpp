#include <iostream>
#include <unordered_set>
using namespace std;
#define MAX_N 100000
#define MAX_K 100000

int n, k;
int a[MAX_K], b[MAX_K];
int arr[MAX_N+1];
int ans[MAX_N+1];
unordered_set<int> s[MAX_N+1];


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>k;

    for(int i=0; i<k; i++) {
        cin >> a[i]>>b[i];
    }

    for(int i=1; i<=n; i++) {
        arr[i] = i;
        s[i].insert(i);
        ans[i] = 1;
    }

    for(int cnt = 0; cnt<3; cnt++) {
        for(int i=0; i<k; i++) {
            swap(arr[a[i]], arr[b[i]]);

            if(s[arr[a[i]]].find(a[i]) == s[arr[a[i]]].end()) {
                s[arr[a[i]]].insert(a[i]);
                ans[arr[a[i]]]++;
            }

            if(s[arr[b[i]]].find(b[i]) == s[arr[b[i]]].end()) {
                s[arr[b[i]]].insert(b[i]);
                ans[arr[b[i]]]++;
            }

        }
    }

    for(int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}