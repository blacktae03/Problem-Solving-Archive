#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp;
    unsigned int tcnt = 0, cnt = 0;
    stack<int> bldg;
    stack<pair<int, unsigned int>> ans;
    cin >> N;
    ans.push({1000000001, 0});

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        bldg.push(tmp);
    }

    for (int j = 0; j < N; j++) {
        tcnt = 0;
        while (bldg.top() > ans.top().first) {
            tcnt = tcnt + ans.top().second + 1;
            ans.pop();
        }
        ans.push({bldg.top(), tcnt});
        bldg.pop();

        cnt += tcnt;
    }
    
    cout << cnt;
}