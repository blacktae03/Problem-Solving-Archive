#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dwf[9] = {0,};
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> dwf[i];
        sum += dwf[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if(dwf[i] + dwf[j] == sum - 100) {
                dwf[i] = 0;
                dwf[j] = 0;
                i = 9;
                j = 9;
            }
        }
    }

    sort(dwf, dwf+9);

    for (int i = 2; i < 9; i++)
        cout << dwf[i] << '\n';
}