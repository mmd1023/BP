// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long

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

bool isPerfect(int n) {
    int sum = 1;
    for (int i = 2; i < n; i++) {
        sum += (n % i == 0)? i:0;
    }
    return sum == n;
}

int main()
{
    int n, prime_count = 0, perfect_count = 0;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        prime_count += (isPrime(i))? 1:0;
        perfect_count += (isPerfect(i))? 1:0;
    }

    cout << prime_count << " " << perfect_count << endl;
    return 0;
}