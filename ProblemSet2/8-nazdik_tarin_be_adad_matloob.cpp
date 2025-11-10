// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long
#define db double

using namespace std;

int main()
{
    int x, n, m;
    cin >> x >> n >> m;

    int i = 0, a;
    while (true)
    {
        a = x - i;

        int digit_low[6] = {a%10, (a/10)%10, (a/100)%10, (a/1000)%10, (a/10000)%10, (a/100000)%10};
        int c_low[4];
        c_low[0] = a % 3 == 0;
        c_low[1] = digit_low[0] == digit_low[5] || a % 18 == 0;
        c_low[2] = digit_low[1] == n;
        c_low[3] = digit_low[2] + digit_low[5] < m;
        if(a >= 100000 && a < 1000000 && c_low[0] * c_low[1] * c_low[2] * c_low[3]) {
            cout << a; 
            return 0;
        }

        
        a = x + i;
        
        int digit_high[6] = {a%10, (a/10)%10, (a/100)%10, (a/1000)%10, (a/10000)%10, (a/100000)%10};
        int c_high[4];
        c_high[0] = a % 3 == 0;
        c_high[1] = digit_high[0] == digit_high[5] || a % 18 == 0;
        c_high[2] = digit_high[1] == n;
        c_high[3] = digit_high[2] + digit_high[5] < m;
        if(a >= 100000 && a < 1000000 && c_high[0] * c_high[1] * c_high[2] * c_high[3]) {
            cout << a;
            return 0;
        }

        i++;
    }
}
