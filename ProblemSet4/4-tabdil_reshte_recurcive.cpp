// writen by mmd
#include <iostream>
using namespace std;

#define ll long long
const ll INF = 1000000000000000000LL;

int solve(string s1, string s2, int n, int m, int i, int j) {
    if (i == n) return m - j; // insert remaining
    if (j == m) return n - i; // delete remaining

    if (s1[i] == s2[j])
        return solve(s1, s2, n, m, i+1, j+1);
    
    int del = solve(s1, s2, n, m, i+1, j);
    int ins = solve(s1, s2, n, m, i, j+1);
    int rplc = solve(s1, s2, n, m, i+1, j+1);

    return min(del, min(ins, rplc)) + 1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    ll n = s1.size(), m = s2.size();
    cout << solve(s1, s2, n, m, 0, 0);
    return 0;
}
