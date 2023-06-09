#include <iostream>
#include <vector>

using namespace std;

class TicTacToe 
{
private:
    vector<vector<char>> board;
    int currentPlayer;
    bool gameOver;

public:
    TicTacToe() 
    {
        board.resize(3, vector<char>(3, ' '));
        currentPlayer = 1;
        gameOver = false;
    }

    void printBoard() 
    {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) 
        {
            cout << "| ";
            for (int j = 0; j < 3; j++) 
            {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    bool makeMove(int row, int col) 
    {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') 
        {
            return false;
        }

        if (currentPlayer == 1) 
        {
            board[row][col] = 'X';
            currentPlayer = 2;
        } 
        else 
        {
            board[row][col] = 'O';
            currentPlayer = 1;
        }

        return true;
    }

    bool checkWin(char player) 
    {
        // Pehle rows check karo
        for (int i = 0; i < 3; i++) 
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }

        // Ab columns check karo
        for (int i = 0; i < 3; i++) 
        {
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }

        // Lastly diagonals check karo
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void playGame() 
    {
        cout << "Tic Tac Toe - Player 1 (X) vs Player 2 (O)" << endl;
        cout << "Enter row and column to make a move (e.g., 1 2):" << endl;

        int row, col;

        while (!gameOver) 
        {
            printBoard();

            cout << "Player " << currentPlayer << ", make your move: ";
            cin >> row >> col;

            if (makeMove(row - 1, col - 1)) 
            {
                if (checkWin('X')) 
                {
                    printBoard();
                    cout << "Player 1 (X) wins!" << endl;
                    gameOver = true;
                } 
                else if (checkWin('O')) 
                {
                    printBoard();
                    cout << "Player 2 (O) wins!" << endl;
                    gameOver = true;
                } 
                else if (isBoardFull()) 
                {
                    printBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                }
            }
            else 
            {
                cout << "Invalid move! Try again." << endl;
            }
        }
    }
};

int main() 
{
    TicTacToe game;
    game.playGame();

    return 0;
}
