#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    while (N--) {
        string str;
        cin >> str;

        cout << str[0] << str[str.length()-1] << '\n';
    }
}