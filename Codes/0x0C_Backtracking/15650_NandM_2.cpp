#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cur, int k) {
    if (cur == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    if (k == n) return;
    
    arr[cur] = k+1;
    func(cur+1, k+1);
    arr[cur] = 0;
    func(cur, k+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0, 0);
}