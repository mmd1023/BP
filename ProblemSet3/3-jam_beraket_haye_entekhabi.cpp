// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define db double

db f(int k, int n, db x, int P) {
    if(P == 1) {
        return x * k / n;
    } else if(P == 2) {
        return (floor(x) * k * k - k * n) / (n * n * 1.0);
    } else if(P == 3) {
        return sqrt(k * n) / n + k * 1.0 / (k+1);
    }
    return 0;
}

int main()
{
    int n, P, sum = 0;
    db x;
    cin >> n >> x >> P;

    for(int k = 0; k < n; k++) {
        sum += floor(x + f(k, n, x, P));
    }

    cout << sum << endl;
    return 0;
}