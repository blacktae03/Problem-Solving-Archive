#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> iput;
    stack<int> ms;
    stack<int> ans;
    int N, tmp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        iput.push(tmp);
    }

    for (int j = 0; j < N; j++) {
        while (ms.empty() == 0 && ms.top() <= iput.top()) {
            ms.pop();
        }

        if (ms.empty())
            ans.push(-1);
        else {
            ans.push(ms.top());
        }
        ms.push(iput.top());
        iput.pop();
    }

    for (int k = 0; k < N; k++) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}