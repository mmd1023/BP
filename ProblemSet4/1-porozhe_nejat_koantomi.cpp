// writen by mmd
#include <iostream>

using namespace std;

// O(logb)
long long recursivePower(long long a, long long b) {
    if (b <= 0)
        return 1;
    // a ^ b = a ^ (b/2) * a ^ (b/2); b = 2k
    // a ^ b = a * a ^ floor(b/2) * a ^ floor(b/2); b = 2k + 1
    long long res = recursivePower(a, b>>1);
    res *= res;
    return (b & 1)? res * a : res;
}

long long recursiveGCD(long long a, long long b) {
    if (b == 0) return a;
    return recursiveGCD(b, a % b);
}

long long sumDigits(long long n) {
    if (n <= 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

bool isPrime(long long n, long long divisor = 5) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    if (divisor * divisor > n) return true;

    if (n % divisor == 0 || n % (divisor + 2) == 0)
        return false;

    return isPrime(n, divisor + 6);
}

long long Gen(long long i) {
    return (isPrime(sumDigits(i)))? recursivePower((i % 5), 3) + 10 :  i * 2;
}

long long Risk(long long i) {
    return recursiveGCD(i, 100) + (i % 10);
} 

int main()
{
    long long n, energy;
    cin >> n >> energy;

    long long i = 1, totalScore = 0, instability = 0, finalScore = 0;
    while (i <= n)
    {
        if (energy >= 5) {
            energy -= 5;
            totalScore += Gen(i);
            i++;
        }
        else if (instability <= 50) {
            energy -= energy / 2;
            instability += Risk(i+1);
            totalScore += 3 * Gen(i+1);
            i += 2;
        }
        else if (energy >= 15 && instability < 20) {
            energy -= 15;
            instability = 0;
            i++;
        } 
        else if (instability >= 100) {
            cout << 1000000 - energy - instability;
            return 0;
        }
        else break;
    }
    
    finalScore = totalScore + energy - instability;
    cout << finalScore;
    return 0;
}
