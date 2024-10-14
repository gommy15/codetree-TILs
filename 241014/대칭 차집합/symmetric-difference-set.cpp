#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int a, b;
vector<int> a_arr, b_arr;
unordered_set<int> a_diff, b_diff;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a>>b;
    int num;
    for(int i=0; i<a; i++) {
        cin >> num;
        a_arr.push_back(num);
        a_diff.insert(num);
    }

    for(int i=0; i<b; i++) {
        cin >> num;
        b_arr.push_back(num);
        b_diff.insert(num);
    }

    unordered_set<int> ans;

    for(int v : a_arr) {
        if(b_diff.find(v) != b_diff.end()) {
            // ans.insert(v);
            b_diff.erase(v);
        }
    }

    for(int v:b_arr) {
        if(a_diff.find(v) != a_diff.end()) {
            // ans.insert(v);
            a_diff.erase(v);
        }
    }

    cout << a_diff.size()+b_diff.size();

    // cout << ans.size();


    return 0;
}