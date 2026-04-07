#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp, same = 1;
    long long tcnt = 0;
    long long cnt = 0;
    cin >> N;
    stack<int> iput;
    stack<pair<int, int>> dms_fwd;
    stack<int> dms_rvs;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        iput.push(tmp);

        while (dms_fwd.empty() == 0 && tmp >= dms_fwd.top().first) {
            tcnt += dms_fwd.top().second;
            if(tmp > dms_fwd.top().first) {
                dms_fwd.pop();
            }
            else {
                same = dms_fwd.top().second+1;
                dms_fwd.pop();
            }   
        }
        cnt += tcnt;
        dms_fwd.push({tmp, same});
        same = 1;
        tcnt = 0;
    }


    for (int j = 0; j < N; j++) {
        tmp = iput.top();
        iput.pop();

        while (dms_rvs.empty() == 0 && tmp > dms_rvs.top()) {
            dms_rvs.pop();
            cnt++;
        }

        dms_rvs.push(tmp);
    }

    cout << cnt;
}