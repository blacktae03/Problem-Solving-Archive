#include <bits/stdc++.h>
using namespace std;

int n, m;
int vcnt, ccnt; // vcnt 모음 개수, ccnt 자음 개수
char arr[15];
char ans[15];

void func(int k, int l) {
    if (k == m) {
        if (vcnt < 1 || ccnt < 2) return;
        for (int i = 0; i < m; i++)
            cout << ans[i];
        cout << '\n';
        return;
    }

    for (int i = l; i < n; i++) {
        ans[k] = arr[i];
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'|| arr[i] == 'o'|| arr[i] == 'u') vcnt++;
        else ccnt++;
        func(k+1, i+1);
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'|| arr[i] == 'o'|| arr[i] == 'u') vcnt--;
        else ccnt--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    func(0, 0);
}