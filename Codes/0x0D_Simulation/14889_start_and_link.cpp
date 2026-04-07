#include <bits/stdc++.h>
using namespace std;

int N;
int brd[21][21];
bool team[21];
int ans = 10000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(team+N/2, team+N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
        }
    }

    do {
        pair<bool, bool> sorl = {0, 0};
        int start = 0, link = 0;

        for (int i = 0; i < N; i++) {
            sorl.first = team[i];

            for (int j = 0; j < N; j++) { 
                sorl.second = team[j];

                if (sorl.first && sorl.second) start += brd[i][j];
                if (!sorl.first && !sorl.second) link += brd[i][j];
            }
        }

        ans = min(ans, abs(start - link));
    } while(next_permutation(team, team+N));

    cout << ans;
}