// writen by mmd
#include <bits/stdc++.h>
using namespace std;

string toBin(int n) {
    string res = "";
    while (!((n & 1)) && n > 0) n >>= 1; // remove front zeros
    
    while (n > 0) {
        res = char((n & 1) + '0') + res;
        n >>= 1;
    }
    return res;
}

bool isPalindrome(const string &s) {
    if (s.size() <= 1) return false; // invalid

    for(int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i]) 
            return false;
    return true;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string n_bin = toBin(n);
        if(n == 0) {
            cout << "YES" << endl;
            continue;
        }
        if((n_bin.size() & 1) && n_bin[n_bin.size()/2] == '1') {
            cout << "NO" << endl;
            continue;
        }
        cout << (isPalindrome(n_bin)? "YES" : "NO") << endl;
    }
    return 0;
}