#include <bits/stdc++.h>
using namespace std;

int need[6] = {1,1,2,2,2,8}, ans[6];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 6; i++) cin >> ans[i];
    for (int i = 0; i < 6; i++) cout << need[i] - ans[i] << ' ';
}