#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 10000010;
int K;
vector<bool> sieze(LIMIT, true);

void func() {
    sieze[1] = false;
    
    for (int i = 2; i*i <= LIMIT; i++) {
        if (!sieze[i]) continue;

        for (int j = i*i; j <= LIMIT; j += i) {
            sieze[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    func();

    for (int i = 1; i < 100; i++) {
        if (!sieze[i]) continue;
        cout << i << ' ';
    }
}