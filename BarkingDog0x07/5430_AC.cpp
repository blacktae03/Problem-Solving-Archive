#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, tmp = 0, cnt = 0;
    string p = "";
    string arr = "";
    deque<int> dq;

    cin >> T;

    while (T--) {
        dq.clear();
        cnt = 0;
        cin >> p >> n >> arr;

        for(char num : arr) {
            if (num == '[') {
                continue;
            }

            else if (num == ',' || num == ']') {
                dq.push_back(tmp);
                tmp = 0;
            }

            else {
                tmp = tmp * 10 + num-'0';
            }
        }

        for (char cmd : p) {
            if (cmd == 'R')
                cnt++;

            else if (cmd == 'D') {
                n--;
                if (n == -1) {
                    break;
                }
                if (cnt % 2 == 1) {
                    dq.pop_back();
                }

                else {
                    dq.pop_front();
                }
                
            }
        }

        if (n > 0) {
            cout << "[";
            while (n--) {
                if(cnt % 2 == 1) {
                    cout << dq.back();
                    if(n!=0) cout << ',';
                    dq.pop_back();
                }

                else {
                    cout << dq.front();
                    if(n!=0) cout << ',';
                    dq.pop_front();
                }
            }
            cout << "]\n"; // \b 쓰면 안된대 ㅅㅂ;;;;;;
        }

        else if (n == 0) {
            cout << "[]\n";
        }

        else {
            cout << "error\n";
        }
        
    }
}