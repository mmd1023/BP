// writen by mmd (fixed)
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// #define ll long long
// #define ldb long double
const long double EPS = 1e-9L;

void add(long double **matrix1, long double **matrix2, long double **matrix3, long long n, long long m) {
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j < m; j++)
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
}

void sub(long double **matrix1, long double **matrix2, long double **matrix3, long long n, long long m) {
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j < m; j++)
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
}

void mul(long double **matrix1, long double **matrix2, long double **matrix3, long long n1, long long m1, long long n2, long long m2) {
    for(long long i = 0; i < n1; i++)
        for(long long j = 0; j < m2; j++) {
            long double sum_ = 0;
            for(long long k = 0; k < m1; k++)
                sum_ += matrix1[i][k] * matrix2[k][j];
            matrix3[i][j] = sum_;
        }
}

bool is_equal(long double **matrix1, long double **matrix2, long long n, long long m) {
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j < m; j++)
            if (fabsl(matrix1[i][j] - matrix2[i][j]) > EPS) return false;
    return true;
}

long double determinan(long double **matrix1, long long n, long long m) {
    if(n == 1 && m == 1) return matrix1[0][0];
    if(n == 2 && m == 2) return matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];

    long double sum_ = 0;
    long double **minorMat = new long double*[n-1];
    for (int i = 0; i < n-1; i++)
        minorMat[i] = new long double[n-1];

    // expansion along first row
    for(long long col = 0; col < n; col++) {
        for(long long i = 0; i < n-1; i++)
            for(long long j = 0; j < n-1; j++)
                minorMat[i][j] = matrix1[i+1][ j < col ? j : j+1 ];

        long double cof = ((col & 1) ? -1 : 1) * matrix1[0][col];
        sum_ += cof * determinan(minorMat, n-1, n-1);
    }

    return sum_;
}

bool inverse(long double **matrix1, long double **matrix2, long long n, long long m) {
    if (n != m) {
        cout << "error size\n";
        return false;
    }

    long double det = determinan(matrix1, n, m);
    if (fabsl(det) < EPS) {
        cout << "determinan is zero!!\n";
        return false;
    }

    // minor buffer
    long double **minorMat = new long double*[n - 1];
    for (int i = 0; i < n - 1; i++)
        minorMat[i] = new long double[n - 1];

    // adjoint matrix
    long double **adj = new long double*[n];
    for (int i = 0; i < n; i++)
        adj[i] = new long double[n];

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int rr = 0;
            for (int i = 0; i < n; i++) {
                if (i == row) continue;
                int cc = 0;
                for (int j = 0; j < n; j++) {
                    if (j == col) continue;
                    minorMat[rr][cc] = matrix1[i][j];
                    cc++;
                }
                rr++;
            }
            long double cof = (((row + col) & 1) ? -1 : 1) * determinan(minorMat, n - 1, n - 1);
            adj[col][row] = cof; // transpose of cofactor matrix
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix2[i][j] = adj[i][j] / det;

    return true;
}

void print(long double **matrix1, long long n, long long m) {
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < m; j++) {
            // trim -0.000... to 0
            if (fabsl(matrix1[i][j]) < EPS) matrix1[i][j] = 0;
            cout << matrix1[i][j];
            if (j+1 < m) cout << " ";
        }
        cout << "\n";
    }
}

void input(long double **matrix1, long long n, long long m) {
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j < m; j++)
            cin >> matrix1[i][j];
}

int main() {
    long long n, m; cin >> n >> m;

    long double **matrix1 = new long double*[n];
    for (int i = 0; i < n; i++)
        matrix1[i] = new long double[m];
    input(matrix1, n, m);

    string cmd; cin >> cmd;
    while (cmd != "exit") {

        if(cmd == "add") {
            long long n2, m2; cin >> n2 >> m2;
            long double **matrix2 = new long double*[n2];
            for (int i = 0; i < n2; i++) matrix2[i] = new long double[m2];
            input(matrix2, n2, m2);

            if (n2 != n || m2 != m) {
                cout << "error size\n";
            } else {
                long double **res = new long double*[n];
                for (int i = 0; i < n; i++) 
                    res[i] = new long double[m];
                add(matrix1, matrix2, res, n, m);
                print(res, n, m);
            }
        }

        else if(cmd == "sub") {
            long long n2, m2; cin >> n2 >> m2;
            long double **matrix2 = new long double*[n2];
            for (int i = 0; i < n2; i++) 
                matrix2[i] = new long double[m2];
            input(matrix2, n2, m2);

            if (n2 != n || m2 != m) {
                cout << "error size\n";
            } else {
                long double **res = new long double*[n];
                for (int i = 0; i < n; i++) res[i] = new long double[m];
                sub(matrix1, matrix2, res, n, m);
                print(res, n, m);
            }
        }

        else if(cmd == "mul") {
            long long n2, m2; cin >> n2 >> m2;
            long double **matrix2 = new long double*[n2];
            for (int i = 0; i < n2; i++) 
                matrix2[i] = new long double[m2];
            input(matrix2, n2, m2);

            if (m != n2) {
                cout << "error size\n";
            } else {
                long double **matrix3 = new long double*[n];
                for (int i = 0; i < n; i++) 
                    matrix3[i] = new long double[m2];

                mul(matrix1, matrix2, matrix3, n, m, n2, m2);
                print(matrix3, n, m2);
            }
        }

        else if(cmd == "determinan") {
            if (n != m)
                cout << "error size\n";
            else
                cout << determinan(matrix1, n, m) << "\n";
        }

        else if(cmd == "inverse") {
            if (n != m) {
                cout << "error size\n";
            } else {
                long double **matrix2 = new long double*[n];
                for (int i = 0; i < n; i++) 
                    matrix2[i] = new long double[m];

                if(inverse(matrix1, matrix2, n, m))
                    print(matrix2, n, m);
            }
        }

        else if(cmd == "equal") {
            long long n2, m2; cin >> n2 >> m2;
            long double **matrix2 = new long double*[n2];
            for (int i = 0; i < n2; i++) 
                matrix2[i] = new long double[m2];
            input(matrix2, n2, m2);

            if (n2 != n || m2 != m)
                cout << "error size\n";
            else
                cout << (is_equal(matrix1, matrix2, n, m) ? "YES" : "NO") << "\n";
        }

        cin >> cmd;
    }

    return 0;
}
