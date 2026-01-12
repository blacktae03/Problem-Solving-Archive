#include <bits/stdc++.h>
using namespace std;

int N, sum;
string str;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> str;

    for (char c : str) sum += c - '0';

    cout << sum;
}