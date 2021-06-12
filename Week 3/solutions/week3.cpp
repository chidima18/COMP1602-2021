#include <iostream>

using namespace std;

// Constants for questions 2-4
#define MAX_COLS 8
#define MAX_ROWS 8

// Alternative for defining constants
//const int COLS = 8;

struct BoardElement
{
    char data;
    bool isBlack;
};

int compare(int list1[], int list2[], int n);
bool isValidLocation(int row, int col);
void printValidNeighbours(int array[][MAX_COLS], int row, int col);

int main()
{
    // Question 3
    int array[MAX_ROWS][MAX_COLS];
    cout << "Checking adjacent elements for [1][1]" << endl;

    printValidNeighbours(array, 1, 1);

    // Question 5
    // a
    BoardElement board[6][6];

    // b
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            board[row][col].data = 'c';
            board[row][col].isBlack = true;
        }
    }

    // c
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            BoardElement elem = board[row][col];
            cout << elem.data << " ";
        }
        cout << endl;
    }

    // d
    board[0][4].data = '7';
    int key = '7';

    for (int col = 0; col < 6; col++)
    {
        if (board[5][col].data == key)
        {
            cout << "Key found at row 0 col " << col;
        }
    }

    return 0;
}

// list1 = [12, 23, 34, 23]
// list2 = [45, 32, 45, 56] returns -1

// list1 = [45, 65, 67, 67]
// list2 = [12, 17, 34, 24] returns 1

// list1 = [45, 17, 67, 67]
// list2 = [12, 65, 34, 67] returns 100

int compare(int list1[], int list2[], int n)
{
    bool hasSmaller = false;
    bool hasGreater = false;

    for (int i = 0; i < n; i++)
    {
        if (list1[i] < list2[i])
        {
            // we know at least one element in list 1 is smaller
            hasSmaller = true;
        }
        if (list1[i] > list2[i])
        {
            // we know at least one element in list 1 is greater
            hasGreater = true;
        }
    }

    // All elements are equal
    if (hasSmaller == false && hasGreater == false)
    {
        return 0;
    }
    // All elements are smaller
    if (hasSmaller == true && hasGreater == false)
    {
        return -1;
    }
    // All elements are greater
    if (hasSmaller == false && hasGreater == true)
    {
        return 1;
    }

    // Otherwise: some elements smaller and some greater
    return 100;
}

bool isValidLocation(int row, int col)
{
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS)
    {
        return true;
    }
    return false;
}

// [row-1][col-1]  [row-1][col]  [row-1][col+1]
// [row  ][col-1]  [row  ][col]  [row  ][col+1]
// [row+1][col-1]  [row+1][col]  [row+1][col+1]

void printValidNeighbours(int array[][MAX_COLS], int row, int col)
{

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (isValidLocation(i, j) == true)
            {
                cout << "Valid - Row: " << i << " Col: " << j << " Value:" << array[i][j] << endl;
            }
        }
    }
}

bool crooked(int cells[MAX_ROWS][MAX_COLS], int size)
{
    int upperCount = 0;
    int lowerCount = 0;

    for (int row = 0; row < MAX_ROWS; row++)
    {
        for (int col = 0; col < MAX_COLS; col++)
        {
            // If cell in upper triangle and is 1
            if (row < col && cells[row][col] == 1)
            {
                upperCount++;
            }
            // If cell in lower triangle and is 1
            if (col < row && cells[row][col] == 1)
            {
                lowerCount++;
            }
        }
    }
    // upper triangle has more 1's
    if (upperCount > lowerCount)
    {
        return true;
    }
    return false;
}
