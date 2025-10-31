// writen by mmd

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll employees[3][4];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> employees[i][j];
        }
    }

    ll sum = 0;
    for(int i = 0; i < 3; i++) {
        employees[i][3] = employees[i][0] + 10000 * employees[i][1] + employees[i][2];
        sum += employees[i][3];

        cout << "Employee " << i+1 << " Final Salary: " << employees[i][3] << endl;
    }

    cout << "Total Salaries: " << sum << endl;
    cout << "Average Salary: " << sum / 3 << endl;
    cout << "Highest Salary: " << max(employees[0][3], max(employees[1][3], employees[2][3])) << endl;
    cout << "Lowest Salary: " << min(employees[0][3], min(employees[1][3], employees[2][3])) << endl;
    return 0;
}
