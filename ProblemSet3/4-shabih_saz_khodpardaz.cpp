// writen by mmd
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long

bool canWithdraw(int &n100, int &n50, int &n10, int q) {
    return (n100*100 + n50*50 + n10*10) >= q;
}

void withdrawMoney(int &n100, int &n50, int &n10, int q) {
    if(q % 10 != 0) {
        cout << "Error: Invalid Amount. Must be a multiple of 10." << endl;
        return;
    }
    if(!canWithdraw(n100, n50, n10, q)) {
        cout << "Error: Not Enough Cash." << endl;
        return;
    }

    int used100 = (q / 100 > n100)? n100:q / 100;
    q -= 100 * used100;
    int used50 = (q / 50 > n50)? n50:q / 50;
    q -= 50 * used50;
    int used10 = (q / 10 > n10)? n10:q / 10;
    q -= 10 * used10;

    if(q != 0) {
        cout << "Error: Cannot dispense exact amount with available bills." << endl;
        return;
    }

    n100 -= used100;
    n50 -= used50;
    n10 -= used10;

    cout << "Dispensing:" << endl;
    cout << used100 << " x 100k" << endl;
    cout << used50 << " x 50k" << endl;
    cout << used10 << " x 10k" << endl;
    cout << "Transaction Successful." << endl;
}

int main()
{
    int n100, n50, n10, q;
    cout << "Enter number of 100k bills: " << endl; cin >> n100;
    cout << "Enter number of 50k bills: " << endl; cin >> n50;
    cout << "Enter number of 10k bills: " << endl; cin >> n10;

    while (1) {
        cout << "Request Amount: " << endl; cin >> q;
        if(q == -1) break;
        withdrawMoney(n100, n50, n10, q);
    }

    if(q == -1) {
        cout << "ATM Shutting Down..." << endl;
        cout << "Remaining Cash:" << endl;
        cout << "100k bills: " << n100 << endl;
        cout << "50k bills: " << n50 << endl;
        cout << "10k bills: " << n10 << endl;
        cout << "Total Value: " << (n100 * 100 + n50 * 50 + n10 * 10) << endl;
    }
    
    return 0;
}