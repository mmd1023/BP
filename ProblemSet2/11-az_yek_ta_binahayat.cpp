// writen by mmd
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow10_[20];

/*
Formula(sum of sum of digits of numbers from 1 to n) 
    = higher * 45 * p
    + (current * (current - 1) // 2) * p
    + current * (lower + 1)
*/
ll digit_sum_1_n(ll n) {
    ll res = 0, p = 1;
    while (n / p > 0) {
        ll higher = n / (p * 10);
        ll current = (n / p) % 10;
        ll lower = n % p;

        res += higher * 45 * p;
        res += (current * (current - 1) / 2) * p;
        res += current * (lower + 1);

        p *= 10;
    }
    return res;
}

int main() {
    pow10_[0] = 1;
    for (int i = 1; i < 20; i++) pow10_[i] = pow10_[i-1] * 10;

    int t; cin >> t;
    ll countr = 1;
    while (t--) {
        ll k = countr++; 
        cin >> k;

        ll sum_len = 0;
        int len = 1;
        while (k > sum_len + len * 9 * pow10_[len - 1]) {
            // i * 9 * 10 ** (i-1)
            sum_len += len * 9 * pow10_[len - 1];
            len++;
        }

        // n = 10 ** len + offset
        ll n = pow10_[len - 1] + (k - sum_len) / len;

        
        // remained digit of last number
        int r_len = (k - sum_len) % len;
        ll r = (r_len == 0)? 0:(n / pow10_[len-r_len]);
        int r_sum = 0;
        
        while (r) {
            r_sum += r % 10;
            r /= 10;
        }
        cout << digit_sum_1_n(n-1) + r_sum << endl;
    }
}
