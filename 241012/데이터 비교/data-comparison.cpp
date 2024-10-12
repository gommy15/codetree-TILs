#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int n, m;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int num;

    unordered_set<int> arr1;

    while(n--) {
        cin >>num;
        arr1.insert(num);
    }

    vector<int> arr2;
    cin >> m;

    for(int i=0; i<m; i++) {
        cin >> num;
        arr2.push_back(num);
    }

    for(auto num : arr2) {
        if(arr1.find(num) == arr1.end()) cout << 0 << ' ';
        else cout << 1 << ' ';
    }
    return 0;
}