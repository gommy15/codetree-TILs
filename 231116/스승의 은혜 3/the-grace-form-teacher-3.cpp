#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_STU 1000

int n, b;
pair<int, int> student[MAX_STU];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n>>b;
    int price, deliv;
    for(int i=0; i<n; i++) {
        cin >> price>>deliv;
        student[i] = make_pair(-price, -deliv);
    }

    sort(student, student+n);

    int max_stunum = INT_MIN;
    for(int i=0; i<n; i++) {
        price = student[i].first;
        deliv = student[i].second;

        int sum = (-price)/2 + (-deliv);
        int stu_num = 1;
        for(int j=i+1; j<n; j++) {
            price = student[j].first;
            deliv = student[j].second;

            sum += ((-price)+(-deliv));
            if(sum >b) break;
            stu_num++;
        }

        max_stunum = max(max_stunum, stu_num);
    }

    cout << max_stunum;
    return 0;
}