// writen by mmd
#include <iostream>
#include <algorithm>

#include <cmath>

#define ll long long
#define db double

using namespace std;

string convert_base(ll num, int base) {
    const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res = "";

    while (num > 0) {
        int r = num % base;
        res += digits[r];
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int b;
    cin >> b;

    for(int i = 1; i <= 300; i++) {
        string pow2_b = convert_base(i * i, b);
        int flag = 1;
        for(int i = 0; i < pow2_b.size() / 2; i++) {
            if(pow2_b[i] != pow2_b[pow2_b.size()-1-i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << convert_base(i, b) << " " << pow2_b << '\n';
        }
    }

    return 0;
}
