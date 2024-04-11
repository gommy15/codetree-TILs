#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string direc;
int num;
vector<int> arr;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> direc;

        if(direc == "push_back") {
            cin >> num;
            arr.push_back(num);
        } else if (direc == "pop_back") {
            arr.pop_back();
        } else if (direc == "size") {
            cout << arr.size() << '\n';
        } else if (direc == "get") {
            cin >> num;
            cout << arr[num-1] << '\n';
        }
    }
    return 0;
}