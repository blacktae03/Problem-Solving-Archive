#include <bits/stdc++.h>
using namespace std;

int N, M;
string Pokedex1[100010];
unordered_map<string, int> Pokedex2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string Pokemon;
        cin >> Pokemon;
        Pokedex1[i] = Pokemon;
        Pokedex2[Pokemon] = i;
    }

    while(M--) {
        string quiz;
        cin >> quiz;
        
        if (quiz[0] > 64) cout << Pokedex2[quiz] << '\n';
        else {
            int num = 0;
            for (char c : quiz) {num *= 10; num += c - '0';}
            cout << Pokedex1[num] << '\n';
        }
    }
}