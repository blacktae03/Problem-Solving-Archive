#include <bits/stdc++.h>
using namespace std;

int grd[50][50];
bool vis[50][50];

int main() {
    int arr[50][50];
    // string c[5];

    // for (int i = 0; i < 5; i++) {
    //     cin >> c[i];
    // }

    // cout << c[0][0] << '\n';

    // for (char a : c[0]) {
    //     cout << a << ' ';
    // }

    // string s = "abcd";

    // s[2] = 'e';

    // cout << s;

//     cout << grd[0][1] << grd[5][7] << grd[10][30] << vis[30][30] << vis[3][3];
//     cout << '\n' << arr[20][20];

    vector<int> v;

    v.push_back(10);
    v.push_back(3);
    v.push_back(5);

    sort(v.begin(), v.end());

    for (auto a : v) {
        cout << a << ' ';
    }
}