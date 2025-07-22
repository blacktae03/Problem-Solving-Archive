#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<int> pos, neg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--) {
        int tmp; cin >> tmp;
        if (tmp > 0) pos.push_back(tmp);
        else neg.push_back(tmp);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    for (int i = pos.size()-1; i >= 0; i -= 2) {
        if (pos[i] == 1 || pos[i-1] == 1) ans += pos[i++]; // ++를 해서 다음에 실행할 증감식을 -1로 상쇄시키기 위함.
        else if (i) ans += pos[i] * pos[i-1];
        else ans += pos[i];
    }

    for (int i = 0; i < neg.size(); i += 2) {
        if (i == neg.size()-1) ans += neg[i];
        else ans += neg[i] * neg[i+1];
    }

    cout << ans;
}
// 일단 기본적인 방법은 양수는 pos 벡터에 넣고, 양이 아닌 정수는 neg 벡터에 넣음. 둘 다 오름차순으로 정렬
// pos는 맨 오른쪽부터 두 개씩 묶어서 곱하여 더함. 큰 수끼리 곱할수록 더 값이 커지기 때문.
// neg는 맨 왼쪽부터 두 개씩 묶어서 곱하여 더함. 절댓값이 큰 음수 두 개를 곱하면 양수가 되며, 값이 가장 커지기 때문. 이때, 필요없는 음수는 없앨 수 있으면 없애는 게 이득이므로 0도 neg에 넣음.
// pos에는 엄청난 예외가 존재함. 바로 1이 곱해지면 손해라는 것. 1은 무조건 더하는 것이 이득. 1 8이 pos에 있다고 할 때, 8 더하고 1 더해야함. 즉, 묶음 안에 1이 있을 때에는 두 수를 각각 더할 수 있게 처리해야함.