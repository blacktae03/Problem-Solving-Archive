#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N*N; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
        if (pq.size() > N) pq.pop();
    }

    cout << pq.top();
}

// 1500 * 1500 = 2,250,000 2메가바이트