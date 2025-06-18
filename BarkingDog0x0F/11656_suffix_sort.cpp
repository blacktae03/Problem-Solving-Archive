#include <bits/stdc++.h>
using namespace std;

string str[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str[0];
    int len = str[0].length();

    for (int i = 1; i < len; i++) {
        for (int j = i; j < len; j++) str[i] += ' '; // 시간초과 안뜨겠지?
        for (int j = i; j < len; j++) {
            str[i][j-i] = str[0][j];
        }
    }


    // for (int i = 0; i < len; i++) cout << str[i] << '\n';
    sort(str, str+len);

    for (int i = 0; i < len; i++) cout << str[i] << '\n';
}