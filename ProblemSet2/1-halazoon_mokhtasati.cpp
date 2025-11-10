// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long
#define db double

using namespace std;

int main()
{
    int n;
    cin >> n;

    int mode = n % 4;
    int depth = n / 4;

    if (mode == 0) {
        cout << -depth << " " << depth;
    } else if (mode == 1) {
        cout << -depth << " " << -depth;
    } else if (mode == 2) {
        cout << depth+1 << " " << -depth;
    } else if (mode == 3) {
        cout << depth+1 << " " << depth+1;
    }
    return 0;
}
