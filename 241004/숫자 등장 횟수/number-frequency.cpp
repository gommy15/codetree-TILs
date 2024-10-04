#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int n, m;
unordered_map<int, int> seq;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>m;

    int num;
    while(n--) {
        cin >> num;
        if(seq.find(num) == seq.end()) {
            seq[num] = 1;
        } else {
            seq[num]++;
        }
    }

    while(m--) {
        cin >> num;
        cout << seq[num] << ' ';
    }
    return 0;
}