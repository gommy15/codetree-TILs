#include <iostream>
#include <unordered_map>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    unordered_map<int, int> hashmap;

    int num;
    while(n--) {
        cin >> num;
        hashmap[num]++;
    }

    cout << (int)hashmap.size();
    return 0; 
}