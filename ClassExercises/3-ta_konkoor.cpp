#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    int s = t % 60;
    t /= 60;
    int m = t % 60;
    t /= 60;
    int h = t % 24;
    t /= 24;
    int d = t;

    cout << d << " days " << h << " hours " << m << " minutes " << s << " seconds" << endl;
    return 0;
}
