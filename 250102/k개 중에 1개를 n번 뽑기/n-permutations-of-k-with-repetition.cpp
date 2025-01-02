#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> ans;

void FindSeq(){
    if(ans.size() == n){
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] <<' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=k; i++) {
        ans.push_back(i);
        FindSeq();
        ans.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k>>n;

    FindSeq();
    return 0;
}