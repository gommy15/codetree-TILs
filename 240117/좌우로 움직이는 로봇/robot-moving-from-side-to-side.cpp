#include <iostream>

#define MAX_T 1000000

using namespace std;

int n, m;
int pos_a[MAX_T  + 1], pos_b[MAX_T + 1];

int main() {
    cin >> n >> m;
    
    int time_a = 1;
    for(int i = 0; i < n; i++) {
        char d; int t;
        cin >> t >> d;
        
        while(t--) {
            if(d == 'R')
                pos_a[time_a] = pos_a[time_a - 1] + 1;
            else
                pos_a[time_a] = pos_a[time_a - 1] - 1;
            
            time_a++;
        }
    }
    
    int time_b = 1;
    for(int i = 0; i < m; i++) {
        int t; char d;
        cin >> t >> d;
        
        while(t--) {
            if(d == 'R')
                pos_b[time_b] = pos_b[time_b - 1] + 1;
            else
                pos_b[time_b] = pos_b[time_b - 1] - 1;
            
            time_b++;
        }
    }
	
	
	if(time_a < time_b) {
		for(int i = time_a; i < time_b; i++) {
			pos_a[i] = pos_a[i - 1];
		}
	}
	else if(time_a > time_b) {
		for(int i = time_b; i < time_a; i++) {
			pos_b[i] = pos_b[i - 1];
		}
	}
    
    int cnt = 0;
	int time_max = 0;
	if(time_a < time_b)
		time_max = time_b;
	else
		time_max = time_a;
	
    for(int i = 1; i < time_max; i++) {
        if(pos_a[i] == pos_b[i] && pos_a[i - 1] != pos_b[i - 1])
            cnt++;
    }
    
    cout << cnt;
    return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define MAX_NM 1000000

// int n, m, t, d;
// int a_arr[MAX_NM+1], b_arr[MAX_NM+1];

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin >> n>>m;

//     int dir_num, now_a = 1;
//     for(int i=0; i<n; i++) {
//         cin >>t>>d;
        
//         if(d == 'L') dir_num = -1;
//         else dir_num = 1;

//         while(t--) {
//             a_arr[now_a] = a_arr[now_a-1] + dir_num;
//             now_a++;
//         }
//     }

//     int now_b = 1;
//     for(int i=0; i<m; i++) {
//         cin >>t>>d;
        
//         if(d == 'L') dir_num = -1;
//         else dir_num = 1;

//         while(t--) {
//             b_arr[now_b] = b_arr[now_b-1] + dir_num;
//             now_b++;
//         }
//     }

//     int max_time;
//     if(now_a > now_b) {
//         for(int i=now_b; i<now_a; i++) {
//             b_arr[i] = b_arr[i-1];
//         }
//         max_time = now_a;
//     } else {
//         for(int i=now_a; i<now_b; i++) {
//             a_arr[i] = a_arr[i-1];
//         }
//         max_time = now_b;
//     }

//     int cnt = 0;
//     for(int i=1; i<max_time; i++) {
//         if(a_arr[i-1] != b_arr[i-1] && a_arr[i] == b_arr[i]) cnt++;
//     }

//     cout << cnt;
//     return 0;
// }