#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int ans[10];
bool isused[10];

void func(int k, int l) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = l; i < n; i++) {
        if (tmp == arr[i]) continue;
        ans[k] = arr[i];
        tmp = ans[k];
        func(k+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr+n);

    func(0, 0);
}