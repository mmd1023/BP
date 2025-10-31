#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int len = log10(n) + 1;

    int first_digit = n % 10;
    int last_digit = int(n / pow(10, len - 1)) % 10;

    n -= last_digit * pow(10, len - 1) + first_digit;
    n += first_digit * pow(10, len - 1) + last_digit;

    cout << n;
    return 0;
}
