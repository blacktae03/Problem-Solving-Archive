#include <bits/stdc++.h>
using namespace std;

int n;
int arr[12];
int ans[6];

void func(int k, int l) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) 
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    if (l == n) return;

    ans[k] = arr[l];
    func(k+1, l+1);
    ans[k] = 0;
    func(k, l+1);

    // 왜 안될까?
    // func(k, l+1);
    // ans[k] = arr[l];
    // func(k+1, l+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (!n) break;
        
        for (int i = 0; i < n; i++) cin >> arr[i];

        func(0, 0);
        cout << '\n';
    }
}