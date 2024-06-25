#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int n;
vector<int> nums;

bool Possible() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i] == nums[j]) {
                if(j == i+1) return false;
                
                int no_seq = false;
                for(int k=0; k<j-i; k++) {
                    if(nums[i+k] != nums[j+k]) {
                        no_seq = true;
                        break;
                    } 
                }
                if(!no_seq) return false;
            }
        }
    }

    return true;
}

void Print() {
    for(int i=0; i<n; i++) {
        cout << nums[i];
    }
}

void FindNum(int cnt) {
    if(cnt == n) {
        if(Possible()) {
            Print();
            exit(0);
        }
        return;
    }

    for(int i=4; i<=6; i++) {
        nums.push_back(i);
        FindNum(cnt +1);
        nums.pop_back();
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    FindNum(0);

    return 0;
}