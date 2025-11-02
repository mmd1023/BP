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
    // for (int i = 0; i < 6; i++) {
    //     if (digit[i] == 3 || digit[i] == 5 || digit[i] == 7)
    //         digit[i]--;
    //     else if (digit[i] == 2)
    //         digit[i] = 0;
    // }
    if (digit[0] == 3 || digit[0] == 5 || digit[0] == 7)
        digit[0]--;
    else if (digit[0] == 2)
        digit[0] = 0;

    if (digit[1] == 3 || digit[1] == 5 || digit[1] == 7)
        digit[1]--;
    else if (digit[1] == 2)
        digit[1] = 0;

    if (digit[2] == 3 || digit[2] == 5 || digit[2] == 7)
        digit[2]--;
    else if (digit[2] == 2)
        digit[2] = 0;

    if (digit[3] == 3 || digit[3] == 5 || digit[3] == 7)
        digit[3]--;
    else if (digit[3] == 2)
        digit[3] = 0;

    if (digit[4] == 3 || digit[4] == 5 || digit[4] == 7)
        digit[4]--;
    else if (digit[4] == 2)
        digit[4] = 0;

    if (digit[5] == 3 || digit[5] == 5 || digit[5] == 7)
        digit[5]--;
    else if (digit[5] == 2)
        digit[5] = 0;

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