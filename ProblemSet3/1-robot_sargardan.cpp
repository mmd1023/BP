// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long

bool canCollect(int prev1, int prev2, int current) {
    int current_copy = current;
    int prev1_sum = 0, prev2_sum = 0, current_sum = 0, digit_max = 0;
    while (prev1 > 0) {
        prev1_sum += prev1 % 10;
        digit_max = max(digit_max, prev1 % 10);
        prev1 /= 10;
    }
    while (prev2 > 0) {
        prev2_sum += prev2 % 10;
        digit_max = max(digit_max, prev2 % 10);
        prev2 /= 10;
    }
    while (current > 0) {
        current_sum += current % 10;
        current /= 10;
    }

    bool c1 = current_sum >= prev1_sum && current_sum >= prev2_sum;
    bool c2 = current_copy % digit_max == 0 || current_sum % 5 == 0;
    return c1 && c2;
}

int main()
{
    int first, second, n, total = 0;
    cin >> n >> first >> second;
    total += first + second;

    for (int i = 2; i < n; i++) {
        int current;
        cin >> current;
        if (canCollect(first, second, current))
            total += current;
        first = second;
        second = current;
    }
    cout << total << endl;
    return 0;
}