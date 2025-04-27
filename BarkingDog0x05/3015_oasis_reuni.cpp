#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp;
    long long cnt = 0;
    cin >> N;
    stack<int> iput;
    stack<int> dms_fwd;
    stack<int> dms_rvs;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        iput.push(tmp);

        while (dms_fwd.empty() == 0 && tmp >= dms_fwd.top()) {
            cnt++;
            if(tmp > dms_fwd.top()) {
                dms_fwd.pop();
            }
            else {
                break;
            }
        }
        
        dms_fwd.push(tmp);
    }

    for (int j = 0; j < N; j++) {
        tmp = iput.top();
        iput.pop();

        while (dms_rvs.empty() == 0 && tmp >= dms_rvs.top()) {
            if(tmp > dms_rvs.top()) {
                cnt++;
            }
            dms_rvs.pop();
        }

        dms_rvs.push(tmp);
        
    }

    cout << cnt;
}