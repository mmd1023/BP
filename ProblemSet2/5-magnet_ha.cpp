// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long
#define db double

using namespace std;

int main()
{
    int n, magnet, last_magnet_polar;
    cin >> n;
    int count = (n > 0)? 1:0;

    cin >> magnet;
    last_magnet_polar = magnet / 10;

    for (int i = 1; i < n; i++) {
        cin >> magnet;
        if (magnet / 10 != last_magnet_polar) {
            last_magnet_polar = magnet / 10;
            count++;
        }
    }
    cout << count;
    return 0;
}
