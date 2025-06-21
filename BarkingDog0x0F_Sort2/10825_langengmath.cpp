#include <bits/stdc++.h>
using namespace std;

int N;
tuple<string, int, int, int> arr[1000001];

bool cmp(const tuple<string, int, int, int> & a, const tuple<string, int, int, int> & b) {
    if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
    else if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
    else if (get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b);
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string name; int lang, eng, math;
        cin >> name >> lang >> eng >> math;

        arr[i] = {name, lang, eng, math};
    }

    sort(arr, arr+N, cmp);

    for (int i = 0; i < N; i++) cout << get<0>(arr[i]) << '\n';
}