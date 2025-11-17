#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll a, b;
    cin >> a >> b;

    ll helper = 2;

    while (a != 0) {
        // n = ceil(b / a)
        ll n = (b + a - 1) / a;
        if (n == 1)
            n = helper++;
        else if (n < helper)
            n = helper++;

        cout << n << " ";
        
        a = a * n - b;
        b = b * n;
    }
    return 0;
}
