#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp, high;
    int cnt = -1;
    stack<int> S;
    stack<int> res;

    cin >> N;
    int M = N;

    S.push(100000001);

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        S.push(tmp);
    }

    N++;
    high = S.top();
    

    while(N--) {
        cnt++;
        if (S.top() > high) { // 4 -> 4 2 1 3 반례.
            
            while(cnt) {
                res.push(N);
                cnt--;
            }

            high = S.top();
        }
        S.pop();
    }

    while(M--) {
        cout << res.top() << ' ';
        res.pop();
    }
}