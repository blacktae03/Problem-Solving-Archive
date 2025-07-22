#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    char buf = 0;
    int num = 0;
    for (auto c : S) {
        if (buf == 0) buf = c;
        else if (buf != c) {
            buf = c;
            num++;
        }
    }

    cout << (num+1) / 2;
}
// num | ans
//  0  |  0
//  1  |  1
//  2  |  1
//  3  |  2
//  4  |  2
// ans = (num+1) / 2