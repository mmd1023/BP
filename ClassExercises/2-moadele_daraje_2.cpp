#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int delta = b*b - 4 * a * c;
    if(delta < 0) return -1;

    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);

    if(x1 > x2) swap(x1, x2);

    cout << fixed << setprecision(3) << x1 << " " << x2 << endl;
    return 0;
}
