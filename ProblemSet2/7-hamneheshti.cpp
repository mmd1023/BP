// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long
#define db double

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 1;

    if(a != b) {
        for (int i = 1; i <= max(a, b); i++) {
            if (a % i == b % i)
                ans *= i;
        }
    }

    cout << ans << "\n";

    string num = to_string(ans);
    int flag = 1;
    
    for(int i = 0; i < num.size() / 2; i++) {
        if(num[i] != num[num.size()-1-i]) {
            flag = 0;
            break;
        }
    }

    cout << ((flag)? "YES":"NO");

    return 0;
}
