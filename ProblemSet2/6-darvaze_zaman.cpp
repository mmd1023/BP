// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long
#define db double

using namespace std;

int main()
{
    string n;
    cin >> n;

    int even_sum = 0, odd_sum = 0, min_num = n[0] - '0', max_num = n[0] - '0';

    for(int i = 0; i < n.size(); i++) {
        int digit = n[i] - '0';
        min_num = min(min_num, digit);
        max_num = max(max_num, digit);
        if (digit & 1) 
            odd_sum += digit;
        else
            even_sum += digit;
    }
    
    if (!(n.size() & 1))
        cout << "Error: The gate only operates in Quantum Asymmetric mode.";
    else if (even_sum != odd_sum)
        cout << "Energy imbalance detected between even and odd digits!";
    else if (int(n[n.size()-1]) - '0' != max_num - min_num)
        cout << "Final energy mismatch! The last digit does not equal the energy gap.";
    else if ((even_sum + odd_sum + (max_num - min_num) + n[n.size()-1] - '0') % 3 == 0)
        cout << "Access Denied! The Time Gate remains sealed.";
    else
        cout << "Time Gate Activated! Access Granted to Temporal Core.";

    return 0;
}
