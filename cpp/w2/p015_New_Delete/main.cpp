#include <iostream>
using namespace std;

int main() {
    int N, i;
    int * arr;

    cin >> N;

    arr = new int[N];

    for(int tmp = 0; tmp < N; tmp++) {
        cin >> arr[tmp];
    }

    cin >> i;

    cout << arr[arr[i]] << endl;

    delete [] arr; // Do not forget.

    return 0;
}