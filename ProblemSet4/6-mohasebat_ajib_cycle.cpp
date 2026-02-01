// writen by mmd
#include <iostream>
using namespace std;

// #define ll long long

// O(log(max(a,b)))
long long sum_a_b(long long a, long long b) {
    long long sum = 0;
    while(a || b) {
        sum += a % 10 + b % 10;
        a /= 10, b /= 10;
    }
    return sum;
}

long long fast_multiply(long long a, long long b) {
    if (b == 0) return 0;
    long long res = 0;
    int seen[163];

    // init
    for (int i = 0; i <= 162; i++) seen[i] = -1;
    long long step = 0;

    while (b--) {
        res = sum_a_b(res, a);

        if (res <= 162) {
            if (seen[res] != -1) {
                long long cycle_len = step - seen[res];
                b %= cycle_len;
            } 
            else 
                seen[res] = step;
        }
        step++;
    }
    return res;
}

long long fast_pow(long long a, long long b) {
    long long res = a; 
    b--;
    while (b > 0) {
        if (b & 1) 
            res = fast_multiply(a, res); // res *= a
        a = fast_multiply(a, a); // a *= a
        b >>= 1;
    }
    return res;
}

int main()
{
    long long t; cin >> t;
    while (t--)
    {
        long long a, b;
        char c;
        cin >> a >> c >> b;
        if (c == '+')
            cout << sum_a_b(a, b) << endl;
        if (c == '*')
            cout << fast_multiply(a, b) << endl;
        if (c == '^')
            cout << fast_pow(a, b) << endl;
    }
    
    return 0;
}
