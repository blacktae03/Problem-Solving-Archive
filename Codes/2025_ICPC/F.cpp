#include <bits/stdc++.h>
using namespace std;

string inp, inv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> inp;
    int sz = inp.size();

    if (sz % 2) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i+1 < sz; i+=2) {
        int cnt = inp[i] - '0';
        char num = inp[i+1];
        char nxtnum = 0;
        if (i+3 < sz) nxtnum = inp[i+3];

        if (num == nxtnum || (i == 0 && num == '0') || !cnt) {
            cout << -1;
            return 0;
        }

        while (cnt--) inv += num;
    }

    cout << inv;
}
