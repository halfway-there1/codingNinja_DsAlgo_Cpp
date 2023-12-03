#include "bits/stdc++.h"
using namespace std;

bool validPos(int row, int col, unordered_map<int, bool> occupied, vector<vector<int>> board, int n) {
    if (occupied[col]) {
        return false;
    }

    // ↖ (i--, j--)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    /* // ↘ (i++, j++)
    for (int i = row, j = col; i < n && j < n; i++, j++) {
        if (board[i][j]) {
            return false;
        }
    }
 */
    // ↗ (i--, j++)
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

   /*  // ↙ (i++, j--)
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    } */

    return true;
}

int N_Queen(vector<vector<int>> board, int n, int row, unordered_map<int, bool> occupied) {
    if (row == n) {
        for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++)
			    cout << board[i][j] << " \n"[j == n-1];
	    }

        cout << "\n";

        return 1;
    }

    int solutions = 0;
    for (int col = 0; col < n; col++) {
        if (validPos(row, col, occupied, board, n)) {
            board[row][col] = 1;
            occupied[col] = true;

            int placed = N_Queen(board, n, row+1, occupied);

            if (placed) {
                solutions++;
            }

            board[row][col] = 0;
            occupied[col] = false;
        }
    }

    if (solutions) {
        return 1;
    }

    return 0;

    // return (solutions > 0);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int> (n, 0));

    /* // column[0] stores the column in which row 0's Queen is placed at.
    vector<int> column(n); */

    // if column[0] == true means column 0 is occupied.
    unordered_map<int, bool> occupied;

    N_Queen(board, n, 0, occupied);

    /* for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << board[i][j] << " \n"[j == n-1];
	} */

    return 0;
}