// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    ll t;
    cin >> t;

    ll current_layer[t] = {2, 3, 5, 7};
    int current_size = 4;

    if(t <= 4) {
        cout << current_layer[t-1];
        return 0;
    }

    ll next_layer[t];
    int next_size = 0;
    t -= 4;
    while (true)
    {
        next_size = 0;
        for(int i = 0; i < current_size; i++) {
            for(int j = 1; j <= 9; j += 2) {
                ll new_num = current_layer[i] * 10 + j;
                if(isPrime(new_num)) {
                    next_layer[next_size++] = new_num;
                    t--;
                    if(t <= 0) {
                        cout << new_num;
                        return 0;
                    }
                }
            }    
        }

        current_size = next_size;
        for(int i = 0; i < current_size; i++)
            current_layer[i] = next_layer[i];
    }

    return 0;
}