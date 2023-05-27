#include<bits/stdc++.h>

using namespace std;
int n;

bool isSafe(int x, int y, vector<bool> rows, vector<bool> leftDiagonals, vector<bool> rightDiagonals) {
    if(rows[x] || leftDiagonals[x + y] || rightDiagonals[y - x + n - 1]){
        return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> leftDiagonals, vector<bool> rightDiagonals){
    if(col >= n) {
        cout<<"--------------------------------------"<<endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]) {
                    cout<<"Q ";
                }
                else {
                    cout<<"_ ";
                }
//                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"--------------------------------------"<<endl;
        return true;
    }

    for(int i = 0; i < n; i++) {
        if(isSafe(i, col, rows, leftDiagonals, rightDiagonals)) {
            leftDiagonals[i + col] = true;
            rightDiagonals[col - i + n - 1] = true;
            rows[i] = true;
            board[i][col] = 1;

            if(solve(board, col+1, rows, leftDiagonals, rightDiagonals)) {
//                return true;
            }

            leftDiagonals[i + col] = false;
            rightDiagonals[col - i + n - 1] = false;
            rows[i] = false;
            board[i][col] = 0;
        }
    }
    return true;
}

int main() {

    cout<<"Enter number of queens: "<<endl;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<bool> rows(n, false), leftDiagonals(n, false), rightDiagonals(n, false);
    solve(board, 0, rows, leftDiagonals, rightDiagonals);
    return 0;
}
