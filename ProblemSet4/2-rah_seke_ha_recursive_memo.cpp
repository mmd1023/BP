// writen by mmd
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000000000LL;

long long memo[1000000];

long long solve(long long c, long long n, long long *coins) {
    if (c == 0) return 0;
    if (c < 0) return INF;

    if (memo[c] != -1) return memo[c];

    long long ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, solve(c - coins[i], n, coins) + 1);

    memo[c] = ans;
    return memo[c];
}

long long solve(long long c, long long n, long long *coins) {
    if (c == 0) return 0;
    if (c < 0) return INF;

    if (memo[c] != -1) return memo[c];

    long long ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, solve(c - coins[i], n, coins) + 1);

    return memo[c] = ans;
}

int main() {
    long long n, cost; cin >> n;
    long long coins[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> cost;

    for (int i = 0; i <= cost; i++)
        memo[i] = -1;

    long long res = solve(cost, n, coins);
    cout << ((res >= INF) ? -1 : res);

    return 0;
}
