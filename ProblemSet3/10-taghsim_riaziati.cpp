// writen by mmd
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

// a ^ b % mod
ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// a / b % MOD
ll mod_div(ll a, ll b) {
    return (a % MOD) * mod_pow(b, MOD - 2, MOD) % MOD;
}

// E(x) = (n * 2^n + (x - 2^n)) / 2^n
ll E(string x) {
    int n = x.size() - 1; 

    ll x_mod = 0;
    for (char c : x)
        x_mod = (x_mod * 2 + (c - '0')) % MOD;

    ll pow_2_n = mod_pow(2, n, MOD);
    ll S = (((n % MOD) * pow_2_n) % MOD + x_mod - pow_2_n + MOD) % MOD;

    return mod_div(S, pow_2_n);
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int _; cin >> _;
        string n; cin >> n;

        cout << E(n) << endl;
    }
    return 0;
}
