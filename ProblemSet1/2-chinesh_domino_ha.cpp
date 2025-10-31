// writen by mmd

#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;

    cout << (((n * m) % 2 == 0)? n*m/2:(n*m-1)/2);
    return 0;
}
