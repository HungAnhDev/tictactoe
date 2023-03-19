#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';
int n;

void draw_board()
{
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void player_turn()
{
    int choice;
    cout << "It's " << player << "'s turn. Enter a number: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        if (board[0][0] == '1')
            board[0][0] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 2:
        if (board[0][1] == '2')
            board[0][1] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 3:
        if (board[0][2] == '3')
            board[0][2] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 4:
        if (board[1][0] == '4')
            board[1][0] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 5:
        if (board[1][1] == '5')
            board[1][1] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 6:
        if (board[1][2] == '6')
            board[1][2] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 7:
        if (board[2][0] == '7')
            board[2][0] = player;
        else

   {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 8:
        if (board[2][1] == '8')
            board[2][1] = player;
        else
        {
            cout<< "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    case 9:
        if (board[2][2] == '9')
            board[2][2] = player;
        else
        {
            cout << "Invalid move, try again." << endl;
            player_turn();
        }
        break;
    default:
        cout << "Invalid move, try again." << endl;
        player_turn();
        break;
    }
}

void switch_player()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char check_winner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return '/';
}

int main()
{
    n = 0;
    draw_board();
    while (1)
    {
        n++;
        player_turn();
        draw_board();
        if (check_winner() == 'X')
        {
            cout << "X wins!" << endl;
            break;
        }
        else if (check_winner() == 'O')
        {
            cout << "O wins!" << endl;
            break;
        }
        else if (check_winner() == '/' && n == 9)
        {
            cout << "It's a tie!" << endl;
            break;
        }
        switch_player();
    }
    return 0;
}
