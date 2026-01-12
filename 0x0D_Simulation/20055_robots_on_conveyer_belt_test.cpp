#include <bits/stdc++.h>
using namespace std;

int N, K, turn;
int brd[210], dur[210];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << turn;
    turn++;
    cout << turn;
    cin >> N >> K;

    for (int i = 1; i <= 2*N; i++) cin >> brd[i];
    
    rotate(brd+1, brd+2*N, brd+2*N+1);
    for (int i = 1; i <= 2*N; i++) cout << brd[i];
    
    
}