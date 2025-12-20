// writen by mmd
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isRotationPrime(int n) {
    int pow_10 = 1, len = 1, temp = n;
    while (temp >= 10) len++, pow_10 *= 10, temp /= 10;
    
    for (int i = 0; i < len; i++) {
        if (!isPrime(n)) 
            return false;
        // if (n / pow_10 == 0) return false;
        n = (n % 10) * pow_10 + (n / 10);
    }
    return true;
}

bool containZero(int n) {
    while (n > 0) {
        if (n % 10 == 0) return true;
        n /= 10;
    }
    return false;
}

int add_k_to_digits(int n, int k) {
    int res = 0, pow_10 = 1;
    while (n > 0) {
        res += pow_10 * ((n % 10 + k) % 10);
        pow_10 *= 10, n /= 10;
    }
    return res;
}

bool check(int n, int m) {
    for (int k = 0; k < m; k++) {
        int nk = add_k_to_digits(n, k);
        if (int(log10(n))+1 != int(log10(nk))+1) return false;
        // if (containZero(nk)) return false;
        if (!isRotationPrime(nk)) return false;
    }
    return true;
}

int main()
{
    int a, b, m, count = 0;
    cin >> a >> b >> m;

    for (int i = a; i <= b; i++) {
        if (check((i), m))
            count++;
    }
    cout << count << endl;
    return 0;
}