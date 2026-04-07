#include <bits/stdc++.h>
using namespace std;

int ans;
string S, E, Q;
unordered_map<string, pair<bool, bool>> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;
    cin.ignore(); // 앞에 무언가가 입력 되고 나면 \n이 포함된 상태로 다음 입력을 받기 때문에 getline 이전에 입력 받은 것이 있다면 ignore을 해줄 필요가 있다.
    string str;
    while(true) {
        getline(cin, str);
        if (str == "") break;

        string time = "", name = "";
        for (int i = 0; i < str.size(); i++) {
            if (i < 5) time += str[i];
            else name += str[i];
        }
        if (time <= S) M[name] = {1, 0};
        if (time >= E && time <= Q) M[name].second += 1;
    }

    for (auto p : M) {
        if (p.second.first == 1 && p.second.second == 1) ans++;
    }

    cout << ans;
}