#include <iostream>
#include <string>
using namespace std;

int m1, d1, m2, d2;
int num_of_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day_name[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> m1>>d1>>m2>>d2;
    string A;
    cin >> A;
    
    int A_idx;
    if(A == "Mon") A_idx=0;
    else if (A == "Tue") A_idx = 1;
    else if (A == "Wed") A_idx = 2;
    else if (A == "Thu") A_idx = 3;
    else if (A == "Fri") A_idx = 4;
    else if (A == "Sat") A_idx = 5;
    else if (A == "Sun") A_idx = 6;


    int days1 = d1, days2 = d2;
    for(int i=1; i<m1; i++) {
        days1+= num_of_month[i];
    }
    for(int i=1; i<m2; i++) {
        days2+= num_of_month[i];
    }

    int diff = days2 - days1;

    // int diff = num_of_month[m1]-d1 + d2;
    // for(int i=m1+1; i<m2; i++) {
    //     diff += num_of_month[i];
    // }

    int cnt = diff/7;
    
    if (diff%7 <= A_idx) cnt++;

    cout << cnt;

    return 0;
}