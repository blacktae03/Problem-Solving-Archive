#include "pointer.h"
#include <iostream>
using namespace std;

int main() {
    int a, b;
    int * pA = &a;
    int * pB = &b;
    
    cin >> *pA >> *pB;
    // == cin >> a >> b;

    update(&a, &b);

    cout << a << endl;
    cout << b << endl;
}