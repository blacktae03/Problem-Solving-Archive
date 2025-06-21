#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << num[i] << ' '; // cout << arr[num[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isused[i]) continue;
        isused[i] = 1;
        num[k] = arr[i];// num[k] = i;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    func(0);
}