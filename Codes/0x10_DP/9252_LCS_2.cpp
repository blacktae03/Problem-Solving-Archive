#include <bits/stdc++.h>
using namespace std;

struct String {
    string s;

    char operator[] (int idx) {
        return s[idx-1];
    }
};

String S1, S2;
pair<int, string> table[1004][1004];
bool mask[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();

    S1 = {s1}, S2 = {s2};

    for (int i = 1; i <= l1; i++) {
        char curi = S1[i];
        
        for (int j = 1; j <= l2; j++) {
            char curj = S2[j];
            pair<int,string>& curState = table[i-1][j-1];

            if (curi == curj) table[i][j] = {curState.first+1, curState.second+curi};
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }

    auto ans = table[l1][l2];

    cout << ans.first << '\n' << ans.second;
}

// LCS 재귀 방식으로 짜야함.

// 왜냐하면 재귀방식으로 짜지 않으면
// 답이 아닌 다른 경우도 봐야하는데 그러면
// string에 겨우 문자하나 추가해서 새로 만드는데 O(N)을 소비해야함.

// 조금 더 간단하게 설명하면 최종 string을 완성하는 과정에서 After = Before + char의 연산을 사용하면 안되고
// After += char의 연산을 사용해야함.

// 더 간단하게 얘기하면 + 를 쓰면 안되고, += 을 써야함.