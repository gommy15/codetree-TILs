#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> seq;

bool IsBeautiful() {
    for(int i=0; i<n; i+=seq[i]) {
        // 연속하여 숫자를 만들 수 없다면 아름다운 수가 아님
        if(i + seq[i]-1 >= n)
            return false;

        for(int j=i; j<i+seq[i]; j++) {
            if(seq[i] != seq[j])
                return false;
        }
    }

    return true;
}

void CountBeautifulSeq(int cnt) {
    if(cnt == n) {
        if(IsBeautiful()) ans++;
        return;
    }

    for(int i=1; i<=4; i++) {
        seq.push_back(i);
        CountBeautifulSeq(cnt+1);
        seq.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    CountBeautifulSeq(0);
    
    cout << ans;
    return 0;
}