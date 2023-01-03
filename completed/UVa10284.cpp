// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=612&page=show_problem&problem=1225
// https://github.com/nexus-x86/cp-solutions
// Tuesday January 3 2023

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int dirX[8] = {0, 0, 1, -1, 1, -1, 1, -1}; // for the king
    int dirY[8] = {1, -1, 0, 0, -1, 1, 1, -1};

    int dirXN[8] = {1, 2, 2, 1, -1, -2, -1, -2}; // for the knight
    int dirYN[8] = {2, 1, -1, -2, 2, 1, -2, -1};

    string chessFEN;
    while (cin >> chessFEN)
    {
        int grid[8][8];
        memset(grid, 0, sizeof(grid));
        // 0 indicating nothing interesting
        // 1 indicating a piece is here
        // 2 indicating a piece is attacking here
        int column = 0;
        int row = 0;
        for (char c : chessFEN)
        {
            int flag = 0;
            if (tolower(c) == 'r' || tolower(c) == 'k' || tolower(c) == 'n' || tolower(c) == 'p' || tolower(c) == 'b' || tolower(c) == 'q')
            {
                grid[row][column] = 1;
            }
            else if (tolower(c) == '/') //
            {
                row++;
                column = 0;
                flag = 1;
            }
            else
            {
                column += c - '0';
                flag = 1;
            }
            if (flag == 0)
            {
                column++;
            }
        }
        row = 0;
        column = 0;
        for (char c : chessFEN)
        {
            // cout << c << " " << column << " " << row << "\n" << flush;
            int flag = 0;
            if (tolower(c) == 'r') // rook
            {
                grid[row][column] = 1;
                if (row + 1 < 8)
                {
                    for (int i = row + 1; i < 8; i++)
                    {
                        if (grid[i][column] == 1)
                        {
                            break;
                        }
                        grid[i][column] = 2;
                    }
                }
                if (row - 1 >= 0)
                {
                    for (int i = row - 1; i >= 0; i--)
                    {
                        if (grid[i][column] == 1)
                        {
                            break;
                        }
                        grid[i][column] = 2;
                    }
                }
                if (column + 1 < 8)
                {
                    for (int i = column + 1; i < 8; i++)
                    {
                        if (grid[row][i] == 1)
                        {
                            break;
                        }
                        grid[row][i] = 2;
                    }
                }
                if (column - 1 >= 0)
                {
                    for (int i = column - 1; i >= 0; i--)
                    {
                        if (grid[row][i] == 1)
                        {
                            break;
                        }
                        grid[row][i] = 2;
                    }
                }
            }
            else if (tolower(c) == 'k') // king
            {
                grid[row][column] = 1;
                for (int i = 0; i < 8; i++)
                {
                    if (row + dirY[i] >= 0 && row + dirY[i] < 8 && column + dirX[i] >= 0 && column + dirX[i] < 8 && grid[row + dirY[i]][column + dirX[i]] != 1)
                    {
                        grid[row + dirY[i]][column + dirX[i]] = 2;
                    }
                }
            }
            else if (tolower(c) == 'n') // knight
            {
                grid[row][column] = 1;
                for (int i = 0; i < 8; i++)
                {
                    if (row + dirYN[i] >= 0 && row + dirYN[i] < 8 && column + dirXN[i] >= 0 && column + dirXN[i] < 8 && grid[row + dirYN[i]][column + dirXN[i]] != 1)
                    {
                        grid[row + dirYN[i]][column + dirXN[i]] = 2;
                    }
                }
            }
            else if (tolower(c) == 'p') // pawn
            {
                grid[row][column] = 1;
                if (c == 'p') // white pawn
                {
                    // cout << row + 1 << " " << column + 1 << " " << grid[row + 1][column + 1] << "\n";
                    if (row + 1 < 8 && column + 1 < 8 && grid[row + 1][column + 1] != 1)
                    {
                        grid[row + 1][column + 1] = 2;
                    }
                    // cout << row + 1 << " " << column - 1 << " " << grid[row + 1][column - 1] << "\n";
                    if (row + 1 < 8 && column - 1 >= 0 && grid[row + 1][column - 1] != 1)
                    {
                        grid[row + 1][column - 1] = 2;
                    }
                }
                else if (c == 'P') // black pawn
                {
                    // cout << row - 1 << " " << column + 1 << " " << grid[row - 1][column + 1] << "\n";
                    if (row - 1 >= 0 && column + 1 < 8 && grid[row - 1][column + 1] != 1)
                    {
                        grid[row - 1][column + 1] = 2;
                    }
                    // cout << row - 1 << " " << column - 1 << " " << grid[row - 1][column - 1] << "\n";
                    if (row - 1 >= 0 && column - 1 >= 0 && grid[row - 1][column - 1] != 1)
                    {
                        grid[row - 1][column - 1] = 2;
                    }
                }
            }
            else if (tolower(c) == 'b') // bishop
            {
                grid[row][column] = 1;
                int i = row + 1;
                int j = column + 1;
                while (i < 8 && j < 8)
                { // checking top right
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i++;
                    j++;
                }
                i = row + 1;
                j = column - 1;
                while (i < 8 && j >= 0)
                { // checking top left
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i++;
                    j--;
                }
                i = row - 1;
                j = column - 1;
                while (i >= 0 && j >= 0)
                { // checking bottom left
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i--;
                    j--;
                }
                i = row - 1;
                j = column + 1;
                while (i >= 0 && j < 8)
                { // checking bottom right
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i--;
                    j++;
                }
            }
            else if (tolower(c) == 'q') // queen
            {
                grid[row][column] = 1;
                int i = row + 1;
                int j = column + 1;
                while (i < 8 && j < 8)
                { // checking top right
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i++;
                    j++;
                }
                i = row + 1;
                j = column - 1;
                while (i < 8 && j >= 0)
                { // checking top left
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i++;
                    j--;
                }
                i = row - 1;
                j = column - 1;
                while (i >= 0 && j >= 0)
                { // checking bottom left
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i--;
                    j--;
                }
                i = row - 1;
                j = column + 1;
                while (i >= 0 && j < 8)
                { // checking bottom right
                    if (grid[i][j] == 1)
                    {
                        break;
                    }
                    grid[i][j] = 2;
                    i--;
                    j++;
                }
                if (row + 1 < 8)
                {
                    for (int i = row + 1; i < 8; i++)
                    {
                        if (grid[i][column] == 1)
                        {
                            break;
                        }
                        grid[i][column] = 2;
                    }
                }
                if (row - 1 >= 0)
                {
                    for (int i = row - 1; i >= 0; i--)
                    {
                        if (grid[i][column] == 1)
                        {
                            break;
                        }
                        grid[i][column] = 2;
                    }
                }
                if (column + 1 < 8)
                {
                    for (int i = column + 1; i < 8; i++)
                    {
                        if (grid[row][i] == 1)
                        {
                            break;
                        }
                        grid[row][i] = 2;
                    }
                }
                if (column - 1 >= 0)
                {
                    for (int i = column - 1; i >= 0; i--)
                    {
                        if (grid[row][i] == 1)
                        {
                            break;
                        }
                        grid[row][i] = 2;
                    }
                }
            }
            else if (tolower(c) == '/') //
            {
                row++;
                column = 0;
                flag = 1;
            }
            else
            {
                column += c - '0';
                flag = 1;
            }
            if (flag == 0)
            {
                column++;
            }
            /*if (column == 8)
            {
                row++;
                column = 0;
            }*/
        }
        int empty = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                // cout << grid[i][j] << " ";
                if (grid[i][j] == 0)
                {
                    empty++;
                }
            }
            // cout << "\n";
        }
        cout << empty << "\n";
    }
}