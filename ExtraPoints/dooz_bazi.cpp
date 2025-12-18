// writen by mmd
#include <iostream>
using namespace std;

#define CONNECT_N 4

int count_dir (char *mat, int n, int m, int i, int j, char player, int di, int dj, int count = 0) {
    if (count >= CONNECT_N - 1 || i >= n || i < 0 || j >= m || j < 0 || mat[i * m + j] != player)
        return count;
    return count_dir(mat, n, m, i+di, j+dj, player, di, dj, count + 1);
}

bool check_win(char *mat, int n, int m, int i, int j, char player) {
    int row_score = count_dir(mat, n, m, i, j-1, player, 0, -1) + 1 + count_dir(mat, n, m, i, j+1, player, 0, 1);
    if (row_score >= CONNECT_N) return true;
    
    int col_score = count_dir(mat, n, m, i-1, j, player, -1, 0) + 1 + count_dir(mat, n, m, i+1, j, player, 1, 0);
    if (col_score >= CONNECT_N) return true;

    int dia1_score = count_dir(mat, n, m, i-1, j-1, player, -1, -1) + 1 + count_dir(mat, n, m, i+1, j+1, player, 1, 1);
    if (dia1_score >= CONNECT_N) return true;

    int dia2_score = count_dir(mat, n, m, i-1, j+1, player, -1, 1) + 1 + count_dir(mat, n, m, i+1, j-1, player, 1, -1);
    if (dia2_score >= CONNECT_N) return true;

    return false;
}

void print_matrix(char *mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i * m + j] << " ";
        }
        cout << "\n";
    }
}

void clearScreen() {
    cout << "\033[2J\033[H";
}

int main() {
    int m, n; cin >> n >> m;
    n = max(n, CONNECT_N), m = max(m, CONNECT_N);
    char matrix[n * m];

    for (int i = 0; i < n * m; i++)
        matrix[i] = '.';

    int last_pos[m];

    for (int i = 0; i < m; i++) 
        last_pos[i] = n;

    print_matrix(matrix, n, m);

    int i = 0;
    while (i < n * m)
    {
        int col; cin >> col;
        col--;
        clearScreen();

        string current_player = (i & 1)? "blue":"red";
        string other_player = (i & 1)? "red":"blue";

        if (col >= m || col < 0 || last_pos[col]-- <= 0) {
            cout << other_player << "!\n"; 
            return 0;
        }

        matrix[last_pos[col] * m + col] = current_player[0];
        print_matrix(matrix, n, m);

        if (check_win(matrix, n, m, last_pos[col], col, current_player[0])) {
            cout << current_player << "!\n"; 
            return 0;
        }
        i++;
    }
    cout << "draw!\n";
    return 0;
}