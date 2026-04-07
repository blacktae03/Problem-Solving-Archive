#include <bits/stdc++.h>
using namespace std;

int sum, ans, ten;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (char c : s) {
        sum += c - '0';
        if (c == '0') ten++;
    }
    
    if (sum % 3 || !ten) cout << -1;
    else {
        sort(s.begin(), s.end(), greater<>());
        for (char c : s) cout << c;
    }
}