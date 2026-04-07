#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len, m, tcnt = 0, cnt = 0, tmp;

    cin >> len >> m;

    queue<int> cirque;

    for (int i = 1; i <= len; i++) {
        cirque.push(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        
        while (cirque.front() != tmp) {
            cirque.push(cirque.front());
            cirque.pop();
            tcnt++;
        }

        cnt += min(tcnt, len-i-tcnt);
        cirque.pop();
        tcnt = 0;
    }

    cout << cnt;
}