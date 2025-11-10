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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i * j) % 3 == 0)
                cout << i * j << " ";
            else if (!((i * j) & 1) && (i * j) % 3 != 0) 
                cout << "@" << " ";
            else if (((i * j) & 1) && (i * j) % 3 != 0)
                cout << "#" << " ";
        }
        cout << "\n";
    }
    return 0;
}
