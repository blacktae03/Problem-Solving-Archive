#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k, int l) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = l; i < n; i++) {
        arr[k] = i+1;
        func(k+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0, 0);
}