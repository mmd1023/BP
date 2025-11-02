// writen by mmd

#include <iostream>
#define ll long long
#define db double

using namespace std;

int main() {
    int n;
    cin >> n;
    int len = (n > 1000)? 5:3;

    if(len == 3) {
        int digit[3] = {(n / 100) % 10, (n / 10) % 10, n % 10};
        if(digit[2] == digit[0])
            cout << n << " is a symmetrical number." << endl;
        else
            cout << digit[2] * 100 + digit[1] * 10 + digit[0] << endl;
    }
    else {
        int digit[5] = {(n / 10000) % 10, (n / 1000) % 10, (n / 100) % 10, (n / 10) % 10, n % 10};
        if(digit[4] == digit[0] && digit[3] == digit[1])
            cout << n << " is a symmetrical number." << endl;
        else
            cout << digit[4] * 10000 + digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0] << endl;
    }
    return 0;
}
