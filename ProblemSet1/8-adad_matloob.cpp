// writen by mmd

#include <iostream>
#define ll long long

using namespace std;

int main() {
    int a, n, m;
    cin >> a >> n >> m;

    int digit[6] = {a%10, (a/10)%10, (a/100)%10, (a/1000)%10, (a/10000)%10, (a/100000)%10};
    int c[4];
    c[0] = a % 3 == 0;
    c[1] = digit[0] == digit[5] || a % 18 == 0;
    c[2] = digit[1] == n;
    c[3] = digit[2] + digit[5] < m;

    if(c[0] * c[1] * c[2] * c[3]) {
        cout << "The value is acceptable.\n"; 
        return 0;
    }

    cout << "The value is not acceptable.\n";
    cout << "Number of unmet conditions: " << 4 - (c[0] + c[1] + c[2] + c[3]) << endl;
    cout << "> Unmet conditions:";
    for(int i = 0; i < 4; i++) {
        cout << ((!c[i])? (" " + to_string(i+1)) : "");
    }
    return 0;
}
