#include <iostream>

using namespace std;

void inc(int * v) {
    (*v)++;
}

// void inc2(int v) {
//     v++;
// }

int main() {
    int a;
    cin >> a;
    inc (&a);
//    inc2(a);
    cout << a;
    return 0;
}