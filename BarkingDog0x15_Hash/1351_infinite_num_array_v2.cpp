#include <bits/stdc++.h>
using namespace std;

int N, P, Q;
unordered_map<int, int> PM, QM;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;
    PM[0] = 1, QM[0] = 1;
    int AP, AQ;

    cout << "P\n";
    for (AP = P; AP <= N; AP += P) {
        PM[AP] = PM[AP/P] + PM[AP/Q];
        cout << AP << " = " << PM[AP] << '\n';
    }
    AP -= P;

    cout << "Q\n";
    for (AQ = Q; AQ <= N; AQ += Q) {
        QM[AQ] = PM[AQ/P] + QM[AQ/Q];
        cout << AQ << " = " << QM[AQ] << '\n';
    }
    AQ -= Q;
    
    cout << PM[AP] + QM[AQ];
}