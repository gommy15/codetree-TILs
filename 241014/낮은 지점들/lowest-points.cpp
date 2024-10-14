#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    
    int x, y;
    unordered_map<int, int> spot;
    for(int i=0; i<n; i++) {
        cin >>x>>y;
        if(spot.find(x) == spot.end()) {
            spot[x] = y;
        } else
            spot[x] = min(spot[x], y);
    }

    int sum = 0;
    for(auto& pair : spot) {
        sum += pair.second;
    }

    cout << sum;
    return 0;
}