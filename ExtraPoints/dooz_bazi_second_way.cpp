#include <iostream>
using namespace std;

// check row
bool check_row(char board[][100], int n, int m, int i, int j, char player) {
    int count = 1, col = j - 1;
    while(col >= 0 && board[i][col] == player && count < 4)
        count++, col--;

    col = j + 1;
    while(col < m && board[i][col] == player && count < 4)
        count++, col++;

    return count >= 4;
}

// check column
bool check_col(char board[][100], int n, int m, int i, int j, char player) {
    int count = 1, row = i - 1;
    while(row >= 0 && board[row][j] == player && count < 4)
        count++, row--;

    row = i + 1;
    while(row < n && board[row][j] == player && count < 4)
        count++, row++;

    return count >= 4;
}

// check diagonal I
bool check_diag1(char board[][100], int n, int m, int i, int j, char player) {
    int count = 1, row = i - 1, col = j - 1;
    while(row >= 0 && col >= 0 && board[row][col] == player && count < 4)
        count++, row--, col--;

    row = i + 1; col = j + 1;
    while(row < n && col < m && board[row][col] == player && count < 4)
        count++, row++, col++;

    return count >= 4;
}

// check diagonal II
bool check_diag2(char board[][100], int n, int m, int i, int j, char player) {
    int count = 1, row = i - 1, col = j + 1;
    while(row >= 0 && col < m && board[row][col] == player && count < 4)
        count++, row--, col++;

    row = i + 1; col = j - 1;
    while(row < n && col >= 0 && board[row][col] == player && count < 4)
        count++, row++, col--;

    return count >= 4;
}

// check all directions
bool does_win(char board[][100], int n, int m, int i, int j, char player) {
    return check_row(board, n, m, i, j, player) ||
           check_col(board, n, m, i, j, player) ||
           check_diag1(board, n, m, i, j, player) ||
           check_diag2(board, n, m, i, j, player);
}

void print_board(char board[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    char board[100][100];
    int last_row[100];

    // initialize board
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = '.';

    for (int j = 0; j < m; j++)
        last_row[j] = n - 1;

    int moves = 0;
    while (moves < n * m)
    {
        int red_col;
        cin >> red_col;
        red_col--;

        if (red_col < 0 || red_col >= m || last_row[red_col] < 0) {
            cout << "blue!" << endl;
            return 0;
        }

        int red_row = last_row[red_col]--;
        board[red_row][red_col] = 'r';

        print_board(board, n, m);

        if (does_win(board, n, m, red_row, red_col, 'r')) {
            cout << "red!" << endl;
            return 0;
        }

        moves++;
        if (moves >= n * m)
            break;

        int blue_col;
        cin >> blue_col;
        blue_col--;
        if (blue_col < 0 || blue_col >= m || last_row[blue_col] < 0) {
            cout << "red!" << endl;
            return 0;
        }

        int blue_row = last_row[blue_col]--;
        board[blue_row][blue_col] = 'b';

        print_board(board, n, m);

        if (does_win(board, n, m, blue_row, blue_col, 'b')) {
            cout << "blue!" << endl;
            return 0;
        }
        moves++;
    }

    cout << "draw!" << endl;
    return 0;
}
