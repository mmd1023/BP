// writen by mmd
#include <iostream>
using namespace std;

// #define ll long long
// #define ldb long double

int indexOf(long long *arr, int n, int value);

bool next_permutation(long long arr[], int n);

int main()
{
    long long n; cin >> n;
    long double matrix[n][n];
    long long row_order[n];

    for(int i = 0; i < n; i++)
        row_order[i] = i;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];

    bool isDominantDiameter = true;
    for(int i = 0; i < n; i++) {
        long double row_sum = 0, diameter = abs(matrix[i][i]);
        for(int j = 0; j < n; j++)
            row_sum += (i == j)? 0:abs(matrix[i][j]);
        if (diameter < row_sum) {
            isDominantDiameter = false;
            break;
        }
    }

    if(isDominantDiameter) {
        cout << "Hast!" << endl;
        return 0;
    }
    else {
        cout << "Nist!" << endl;
        while(next_permutation(row_order, n)) {
            bool isDominantDiameter = true;
            for(int index = 0; index < n; index++) {
                int i = row_order[index];
                long double row_sum = 0, diameter = abs(matrix[index][i]);
                for(int j = 0; j < n; j++)
                    row_sum += (i == j)? 0:abs(matrix[index][j]);
                if (diameter < row_sum) {
                    isDominantDiameter = false;
                    break;
                }
            }
            if(isDominantDiameter) {
                for(int index = 0; index < n; index++) {
                    int i = indexOf(row_order, n, index);
                    for(int j = 0; j < n; j++)
                        cout << matrix[i][j] << " ";
                    cout << "\n";
                }
                return 0;
            }
        }
        cout << "Peyda Nemishe!" << endl;
    }
    return 0;
}

int indexOf(long long *arr, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

bool next_permutation(long long arr[], int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return false;

    int j = n - 1;
    while (arr[j] <= arr[i]) j--;

    swap(arr[i], arr[j]);

    // reverse
    int l = i + 1, r = n - 1;
    while (l < r) swap(arr[l++], arr[r--]);
    return true;
}