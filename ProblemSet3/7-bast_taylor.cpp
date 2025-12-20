// writen by mmd
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double

int main()
{
    int mode; cin >> mode;
    ldb x; cin >> x;
    int n; cin >> n;

    ldb x_pow_n = 1, res = 0;
    ll fact_n = 1;

    // e ^ x = 1 + x/1! + x^2/2! + x^3/3! + ...
    if (mode == 1) {
        if (n == 1) {
            cout << "1" << endl << 1 << endl;
            return 0;
        }
        else if (n == 2) {
            cout << "1 + x" << endl << 1 + x << endl;
            return 0;
        }
        cout << "1 + x";
        res = 1 + x;
        x_pow_n = x;
        for (int i = 2; i < n; i++) {
            x_pow_n *= x;
            fact_n *= i;
            
            res += x_pow_n / fact_n;
            cout << " + x^" << i << "/" << fact_n;
        }
        cout << endl << res << endl;
    }

    // sin x = x - x^3/3! + x^5/5! - x^7/7! + ...
    else if (mode == 2) {
        cout << "x";
        res = x_pow_n = x, fact_n = 1;
        for (int i = 1; i < n; i++) {
            x_pow_n *= x * x;
            fact_n *= 2*i * (2*i + 1);
            
            res += ((i&1)? -1:1) * x_pow_n / fact_n;
            cout << ((i&1)? " - ":" + ") << "x^" << 2*i+1 << "/" << fact_n;
        }
        cout << endl << res << endl;
    } 

    // cos x = 1 - x^2/2! + x^4/4! - x^6/6! + ...
    else if (mode == 3) {
        cout << "1";
        res = x_pow_n = fact_n = 1;

        for (int i = 1; i < n; i++) {
            x_pow_n *= x * x;
            fact_n *= 2*i * (2*i - 1);
            
            res += ((i&1)? -1:1) * x_pow_n / fact_n;
            cout << ((i&1)? " - ":" + ") << "x^" << 2*i << "/" << fact_n;
        }
        cout << endl << res << endl;
    }
    return 0;
}
