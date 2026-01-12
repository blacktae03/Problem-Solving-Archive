#include <bits/stdc++.h>
using namespace std;

bool nums[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M; cin >> M;
    string com;
    int num;

    while(M--) {
        cin >> com;

        if (com == "add") {
            cin >> num;
            nums[num] = 1;
        }

        else if (com == "remove") {
            cin >> num;
            nums[num] = 0;
        }

        else if (com == "check") {
            cin >> num;
            cout << nums[num] << '\n';
        }

        else if (com == "toggle") {
            cin >> num;
            nums[num] = !nums[num];
        }

        else if (com == "all") fill(nums+1, nums+21, 1);

        else if (com == "empty") fill(nums+1, nums+21, 0);
    }
}