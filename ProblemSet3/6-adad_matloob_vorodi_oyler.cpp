// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define ldb long double

int find_matloob(int x, int n, int m) {
    int i = 0, a = 0;
    while (true) {
        a = x - i;
        int d0 = a % 10, d1 = (a / 10) % 10, d2 = (a / 100) % 10, d3 = (a / 1000) % 10, d4 = (a / 10000) % 10, d5 = (a / 100000) % 10;
        int c0 = (a % 3 == 0), c1 = (d0 == d5 || a % 18 == 0), c2 = (d1 == n), c3 = (d2 + d5 < m);
        if (a >= 100000 && a < 1000000 && c0 * c1 * c2 * c3) {
            // cout << a;
            return a;
        }

        a = x + i;
        d0 = a % 10, d1 = (a / 10) % 10, d2 = (a / 100) % 10, d3 = (a / 1000) % 10, d4 = (a / 10000) % 10, d5 = (a / 100000) % 10;
        c0 = (a % 3 == 0), c1 = (d0 == d5 || a % 18 == 0), c2 = (d1 == n), c3 = (d2 + d5 < m);
        if (a >= 100000 && a < 1000000 && c0 * c1 * c2 * c3) {
            // cout << a;
            return a;
        }
        i++;
    }
}

// z + z̄ = i + secy + i(cscy)^2 - secy = i (1 + (cscy)^2) = i (2 + (coty)^2)
void calc_zz_sum(ldb y) {
    ldb siny = sin(y);
    cout << (1 + 1/(siny * siny)) << "i + 0\n";
}


int main()
{
    int x, n, m, i, j, k, p, q, r;
    cin >> x >> n >> m >> i >> j >> k >> p >> q >> r;

    int h = find_matloob(x, n, m);
    int f = h % 10, e = (h / 10) % 10, d = (h / 100) % 10, c = (h / 1000) % 10, b = (h / 10000) % 10, a = (h / 100000) % 10;
    
    ldb s1 = log10(abs(log10(abs(pow(a, i) - pow(c, j) + pow(e, k) + a * 100 + c * 10 + e))));
    ldb s2 = log10(abs(log10(abs(pow(b, p) - pow(d, q) + pow(f, r) - 2 * (b * 100 + d * 10 + f)))));
    
    ldb y = asin((s1 + s2) / 2);
    
    calc_zz_sum(y);
    return 0;
}
