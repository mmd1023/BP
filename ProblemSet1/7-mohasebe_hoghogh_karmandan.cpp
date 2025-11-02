// writen by mmd

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll employees[3][4];

    cin >> employees[0][0];
    cin >> employees[0][1];
    cin >> employees[0][2];

    cin >> employees[1][0];
    cin >> employees[1][1];
    cin >> employees[1][2];

    cin >> employees[2][0];
    cin >> employees[2][1];
    cin >> employees[2][2];

    ll sum = 0;

    employees[0][3] = employees[0][0] + 10000 * employees[0][1] + employees[0][2];
    sum += employees[0][3];
    cout << "Employee " << 1 << " Final Salary: " << employees[0][3] << endl;

    employees[1][3] = employees[1][0] + 10000 * employees[1][1] + employees[1][2];
    sum += employees[1][3];
    cout << "Employee " << 2 << " Final Salary: " << employees[1][3] << endl;

    employees[2][3] = employees[2][0] + 10000 * employees[2][1] + employees[2][2];
    sum += employees[2][3];
    cout << "Employee " << 3 << " Final Salary: " << employees[2][3] << endl;


    cout << "Total Salaries: " << sum << endl;
    cout << "Average Salary: " << sum / 3 << endl;
    cout << "Highest Salary: " << max(employees[0][3], max(employees[1][3], employees[2][3])) << endl;
    cout << "Lowest Salary: " << min(employees[0][3], min(employees[1][3], employees[2][3])) << endl;
    return 0;
}
