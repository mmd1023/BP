// writen by mmd

#include <iostream>
#define ll long long
#define db double

using namespace std;

int main() {
    string fruits[5] = {"apple", "banana", "peach", "lemon", "kiwi"};
    int cal[5] = {100, 250, 70, 45, 85};

    string fruit;
    db amount = 0;
    cin >> fruit >> amount;

    ll totual = 0;
    // for(int i = 0; i < 5; i++) {
    //     if(fruit == fruits[i]) {
    //         totual = amount * cal[i];
    //     }
    // }
    if (fruit == fruits[0])
        totual = amount * cal[0];
    else if (fruit == fruits[1])
        totual = amount * cal[1];
    else if (fruit == fruits[2])
        totual = amount * cal[2];
    else if (fruit == fruits[3])
        totual = amount * cal[3];
    else if (fruit == fruits[4])
        totual = amount * cal[4];

    cout << totual << endl;

    if(totual > 200) {
        cout << "more" << endl;
    } else if(totual < 100) {
        cout << "less" << endl;
    } else {
        cout << "ok" << endl;
    }
    return 0;
}
