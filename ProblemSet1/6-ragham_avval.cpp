// writen by mmd
#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
    int a;
    cin >> a;

    int digit[6] = {(a / 100000) % 10, (a / 10000) % 10, (a / 1000) % 10, (a / 100) % 10, (a / 10) % 10, a % 10};

    int is_started = 0;
    for (int i = 0; i < 6; i++) {
        if (digit[i] == 3 || digit[i] == 5 || digit[i] == 7)
            digit[i]--;
        else if (digit[i] == 2)
            digit[i] = 0;
    }

    int n = 100000 * digit[0] + 10000 * digit[1] + 1000 * digit[2] + 100 * digit[3] + 10 * digit[4] + digit[5];
    cout << n;
    return 0;
}



// // writen by mmd
// #include <iostream>
// #include <cmath>

// #define ll long long

// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;
//     for (int i = 0; i < s.size(); i++) {
//         int d = s[i] - '0';
//         if (d == 3 || d == 5 || d == 7)
//             d--;
//         else if (d == 2)
//             d = 0;
//         s[i] = d + '0';
//     }
//     cout << stod(s);
//     return 0;
// }