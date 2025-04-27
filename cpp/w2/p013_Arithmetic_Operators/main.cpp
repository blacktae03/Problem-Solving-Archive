#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float num1, num2;

    cout.precision(2);

    cin >> num1 >> num2;

    cout << fixed << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << fixed << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << fixed << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << fixed << num1 << " / " << num2 << " = " << num1 / num2 << endl;

    return 0;
}