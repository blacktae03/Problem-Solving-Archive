#include <memory>
#include <iostream>
using namespace std;

int main() {
    int a = 1;

    unique_ptr<int> pi1 = unique_ptr<int> {new int{a}};
    unique_ptr<int> pi2 {new int{2}};
    auto pi3 = unique_ptr<int> {new int {3}};
    auto pi4 = make_unique<int*>(new int {4});

    cout << *pi1 << "\t" << *pi2 << "\t" << *pi3 << "\t" << **pi4 << endl;
}