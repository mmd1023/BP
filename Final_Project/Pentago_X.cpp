// writen by mmd
// Pentago_X
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace chrono;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

char SKIN[] = {'O', 'X'};
atomic<bool> running(true);
atomic<int> mins(0), secs(0);

void timer_thread() {
    auto last = steady_clock::now();
    while (running) {
        auto now = steady_clock::now();
        if (duration_cast<seconds>(now - last).count() >= 1) {
            last = now;
            secs++;
            if (secs >= 60) {
                secs = 0;
                mins++;
            }
            cout << "\rTIME: " << setw(2) << setfill('0') << mins << ":" << setw(2) << setfill('0') << secs << "  |  Input: " << flush;
        }
        this_thread::sleep_for(milliseconds(10)); // CPU friendly
    }
}

int count_dir (unsigned char **borad, int n, int i, int j, char player, int di, int dj, int k, int count = 0) {
    if (count >= k - 1 || i >= n || i < 0 || j >= n || j < 0 || borad[i][j] != player)
        return count;
    return count_dir(borad, n, i+di, j+dj, player, di, dj, k, count + 1);
}

bool check_win(unsigned char **mat, int n, int i, int j, char player, int k) {
    int row_score = count_dir(mat, n, i, j-1, player, 0, -1, k) + 1 + count_dir(mat, n, i, j+1, player, 0, 1, k);
    if (row_score >= k) return true;
    
    int col_score = count_dir(mat, n, i-1, j, player, -1, 0, k) + 1 + count_dir(mat, n, i+1, j, player, 1, 0, k);
    if (col_score >= k) return true;

    int dia1_score = count_dir(mat, n, i-1, j-1, player, -1, -1, k) + 1 + count_dir(mat, n, i+1, j+1, player, 1, 1, k);
    if (dia1_score >= k) return true;

    int dia2_score = count_dir(mat, n, i-1, j+1, player, -1, 1, k) + 1 + count_dir(mat, n, i+1, j-1, player, 1, -1, k);
    if (dia2_score >= k) return true;

    return false;
}

void check_win_border(unsigned char **board, int n, int k, int block_id, bool &first_win, bool &second_win) {
    if (block_id == 1) {
        for (int i = 0; i < n/2; i++) // right border
            if (check_win(board, n, i, n/2-1, board[i][n/2-1], k)) if(board[i][n/2-1] == 'O') first_win = true; else if(board[i][n/2-1] == 'X') second_win = true;
        
        for (int j = 0; j < n/2; j++) // bottom border
            if (check_win(board, n, n/2-1, j, board[n/2-1][j], k)) if(board[n/2-1][j] == 'O') first_win = true; else if(board[n/2-1][j] == 'X') second_win = true;
    }
    else if (block_id == 2) {
        for (int i = 0; i < n/2; i++) // left border
            if (check_win(board, n, i, n/2, board[i][n/2], k)) if(board[i][n/2] == 'O') first_win = true; else if(board[i][n/2] == 'X') second_win = true;
        
        for (int j = n/2; j < n; j++) // bottom border
            if (check_win(board, n, n/2-1, j, board[n/2-1][j], k)) if(board[n/2-1][j] == 'O') first_win = true; else if(board[n/2-1][j] == 'X') second_win = true;
    }
    else if (block_id == 3) {
        for (int j = 0; j < n/2; j++) // top border
            if (check_win(board, n, n/2, j, board[n/2][j], k)) if(board[n/2][j] == 'O') first_win = true; else if(board[n/2][j] == 'X') second_win = true;
        for (int i = n/2; i < n; i++) // right border
            if (check_win(board, n, i, n/2-1, board[i][n/2-1], k)) if(board[i][n/2-1] == 'O') first_win = true; else if(board[i][n/2-1] == 'X') second_win = true;
    }
    else if (block_id == 4) {
        for (int j = n/2; j < n; j++) // top border
            if (check_win(board, n, n/2, j, board[n/2][j], k)) if(board[n/2][j] == 'O') first_win = true; else if(board[n/2][j] == 'X') second_win = true;
        
        for (int i = n/2; i < n; i++) // left border
            if (check_win(board, n, i, n/2, board[i][n/2], k)) if(board[i][n/2] == 'O') first_win = true; else if(board[i][n/2] == 'X') second_win = true;
    }
}

void check_win_all(unsigned char **board, int n, int k, int block_id, int last_x, int last_y, bool &first_win, bool &second_win) {
    char player = board[last_x][last_y];
    if (check_win(board, n, last_x, last_y, player, k)) {
        if (player == 'O') first_win = true; 
        else if (player == 'X') second_win = true;
    }
    check_win_border(board, n, k, block_id, first_win, second_win);
}

void rotate_block(unsigned char **board, int n, int start_x, int start_y, bool clockwise) {
    unsigned char temp[n/2][n/2];
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            temp[i][j] = board[start_x + i][start_y + j];

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (clockwise)
                board[start_x + j][start_y + (n / 2 - 1 - i)] = temp[i][j]; // (i, j) -> (j, n/2-1-i)
            else
                board[start_x + (n / 2 - 1 - j)][start_y + i] = temp[i][j]; // (i, j) -> (n/2-1-j, i)
        }
    }
}

void save(unsigned char **board, int n, int k, int step, int min, int sec) {
    ofstream file("config.txt");
    file << n << " " << k << " " << step << "\n" << min << " " << sec << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            file << board[i][j] << " ";
        file << "\n";
    }
}

void load(unsigned char **&board, int &n, int &k, int &step, atomic<int> &min, atomic<int> &sec) {
    ifstream file("config.txt");
    int m, s;
    file >> n >> k >> step >> m >> s;
    min = m, sec = s;

    board = new unsigned char*[n];
    for(int i = 0; i < n; i++) {
        board[i] = new unsigned char[n];
        for (int j = 0; j < n; j++)
            file >> board[i][j];
    }   
}

void print_board(unsigned char **board, int n, int k, int p) {
    cout << string(50, '=') << "\nP1: [O] | P2: [X] | BLOCK: " << n/2 << "x" << n/2 << " | WIN GOAL (k): " << k << "\n";
    cout << "BLOCKS ID: [1] [2] [3] [4]\n[COMMANDS] -Move: row col , -Rotate: ID Dir , -(S)ave & Exit\n" << string(50, '=') << "\n";
    cout << "   " << CYAN;
    for (int i = 0; i < n; i++) cout << (i == n / 2 ? "   ":" ") << char(i > 9 ? (i - 10) + 'A':i+'0');

    cout << RESET << "\n  +";
    for (int j = 0; j < n+1; j++) cout << "--";
    cout << "-+\n";

    for (int i = 0; i < n; i++) {
        if(i == n / 2) {
            cout << "  +";
            for (int j = 0; j < n+1; j++) cout << "--";
            cout << "-+\n";
        }
        cout << CYAN << char(i > 9 ? (i - 10) + 'A':i+'0') << RESET << " | ";
        for (int j = 0; j < n; j++) {
            if (j == n/2) cout << "| ";
            cout << (board[i][j] == 'O' ? YELLOW:(board[i][j] == 'X' ? MAGENTA:RESET)) << board[i][j] << RESET << " ";
        }
        cout << "|\n";
    }
    cout << "  +";
    for (int j = 0; j < n+1; j++) cout << "--";
    cout << "-+\n";

    cout << "CURRENT TURN: PLAYER " << p <<"\n";
}

void clearScreen() {
    cout << "\033[2J\033[H";
}

void refresh(unsigned char **board, int n, int k, int p) {
    clearScreen();
    print_board(board, n, k, p);
}

int main() {
    unsigned char **board;
    int n, k, step = 0;

    while (1) { // menu
        cout << "Choose to:\n 1. New Game\n 2. Load Game\n 3. Exit\n";
        string mode; cin >> mode;
        if(mode == "1" || mode == "new game") {
            cin >> n >> k;
            if (n < 3 || n > 8 || k <= n || k >= n*2) {
                clearScreen();
                cout << RED << "Invalid input!\n3 <= n <= 8  ,  n < k < 2n\n" << RESET;
                continue;
            }
            n <<= 1;
        
            board = new unsigned char*[n];
            for(int i = 0; i < n; i++) {
                board[i] = new unsigned char[n];
                for(int j = 0; j < n; j++)
                    board[i][j] = '.';
            }
            break;
        }
        else if(mode == "2" || mode == "load game") {
            cout << GREEN << "Game loaded!\n" << RESET;
            load(board, n, k, step, mins, secs);
            break;
        }
        else if(mode == "3" || mode == "exit")
            return 0;
        cout << RED << "Invalid input! please enter 1, 2 or 3.\n" << RESET;
    }
    
    refresh(board, n, k, 1);
    thread t(timer_thread);

    while (1) {
        cout << "Enter your move (i , j) ...\n";
        string tmp;
        cin >> tmp;
        if(tmp == "s" || tmp == "S") {
            cout << GREEN << "Game saved!\n" << RESET;
            save(board, n, k, step, mins, secs);
            break;
        } 
        else if (tmp == "Exit" || tmp == "exit" || tmp == "q") {
            cout << RED << "Exit!\n" << RESET;
            break;
        }
        
        int x = (tmp[0] >= 'A')? tmp[0]-'A'+10:stoi(tmp); 
        cin >> tmp;
        int y = (tmp[0] >= 'A')? tmp[0]-'A'+10:stoi(tmp); 
        if (x < 0 || y < 0 || x >= n || y >= n || board[x][y] != '.') {
            cout << RED << "Invalid Posision!\n" << RESET;
            continue;
        }
        board[x][y] = SKIN[step&1];
        refresh(board, n, k, (step&1)+1);

        cout << "Enter your rotation block_id , direction(R/L) ...\n";
        int block_id; char dir;
        cin >> block_id >> dir;
        if (block_id < 1 || block_id > 4 || (dir != 'L' && dir != 'R')) {
            cout << RED << "Invalid Rotation!\n" << RESET;
            board[x][y] = '.';
            continue;
        }
        int block_pos[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int start_x = block_pos[block_id-1][0] * (n / 2);
        int start_y = block_pos[block_id-1][1] * (n / 2);
        rotate_block(board, n, start_x, start_y, dir == 'R');
        refresh(board, n, k, (++step&1) + 1);

        if (x >= start_x && x < start_x + n/2 && y >= start_y && y < start_y + n/2) { // in rotated block
            // reletive posision
            x -= (block_id > 2 ? n/2 : 0);
            y -= (block_id % 2 == 0 ? n/2 : 0);
            // rotated posision
            if (dir == 'R') { 
                int temp = x;
                x = y, y = n/2 - 1 - temp;
            } else {
                int temp = x;
                x = n/2 - 1 - y, y = temp;
            }
            // absolute posision
            x += (block_id > 2 ? n/2 : 0);
            y += (block_id % 2 == 0 ? n/2 : 0);
        }

        bool first_win = false, second_win = false;
        check_win_all(board, n, k, block_id, x, y, first_win, second_win);

        if(first_win && second_win) {
            cout << GREEN << "\n" << string(30, '*') << "\n*" << string(11, ' ') << " DRAW!" << string(11, ' ') << "*\n" << string(30, '*')  << "\n\n" << RESET;
            break;
        }
        if (first_win) {
            cout << GREEN << "\n" << string(30, '*') << "\n*" << string(7, ' ') << "PLAYER 1 WINS!" << string(7, ' ') << "*\n" << string(30, '*') << "\n\n" << RESET;
            break;
        }
        if (second_win) {
            cout << GREEN << "\n" << string(30, '*') << "\n*" << string(7, ' ') << "PLAYER 2 WINS!" << string(7, ' ') << "*\n" << string(30, '*') << "\n\n" << RESET;
            break;
        }
        if (step >= n * n) {
            cout << GREEN << "\n" << string(30, '*') << "\n*" << string(11, ' ') << " DRAW!" << string(11, ' ') << "*\n" << string(30, '*') << "\n\n" << RESET;
            break;
        }
    }
    running = false;
    t.join();

    for(int i = 0; i < n; i++)
        delete[] board[i];
    delete[] board;
    return 0;
}