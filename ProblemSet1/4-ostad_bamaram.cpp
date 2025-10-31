// writen by mmd

#include <iostream>
#include <iomanip>
#define ll long long
#define db double

using namespace std;

int main() {
    db mid, final;
    db score = 0;

    cin >> mid >> final;

    if(final >= 11 || mid + final >= 18)
        score = 20;
    else if(mid + final >= 14)
        score = 1.1 * (mid + final);
    else
        score = 1.05 * (mid + final);
        
    cout << score;
    return 0;
}
