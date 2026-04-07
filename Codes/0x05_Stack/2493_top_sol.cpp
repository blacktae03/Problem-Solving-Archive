// 답 보기 전에 못 푼 문제.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tmp;
    stack<pair<int, int>> s;
    s.push({100000001, 0});
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> tmp;

        while (s.top().first < tmp) {
            s.pop();
        }
        if (s.top().first > tmp) {
            cout << s.top().second << ' ';
            s.push({tmp, i});
        }
    }
}