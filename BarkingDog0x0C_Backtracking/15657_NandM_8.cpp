#include <bits/stdc++.h>
using namespace std;

int n, m;
int idx[10];

void func(int k, int l, int * arr) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[idx[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = l; i < n; i++) {
        idx[k] = i;
        func(k+1, i, arr);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    func(0, 0, arr);
}