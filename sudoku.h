#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int EMPTY = 0;
const int N = 9;
int grid[N][N];

bool checkRow(int grid[N][N], int row, int num){
    for(int col = 0; col < N; col++)
        if(grid[row][col] == num)
            return false;
    return true;
}

bool checkColumn(int grid[N][N], int col, int num){
    for(int row = 0; row < N; row++)
        if(grid[row][col] == num)
            return false;
    return true;
}

bool checkBox(int grid[N][N], int startRow, int startCol, int num){
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            if(grid[row + startRow][col + startCol] == num)
                return false;
    return true;
}

bool getPosition(int grid[N][N], int &row, int &col){
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(grid[row][col] == EMPTY)
                return true;
    //End of grid, evaluation complete
    return false;
}

void printGrid(int grid[N][N]){
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if(!getPosition(grid, row, col))
        return true;
    for(int n = 1; n <= 9; n++){
        if(checkRow(grid, row, n) && checkColumn(grid, col, n) && checkBox(grid, row - row % 3, col - col % 3, n)){
            grid[row][col] = n;
            if(solveSudoku(grid))
                return true;
        }
    }
    grid[row][col] = EMPTY;
    return false;
}

void readFile(char fileName[], int grid[N][N]){
    ifstream gridFile;
    int row = 0;
    string line;
    gridFile.open(fileName);
    while(!gridFile.eof()){
        if(!getline(gridFile, line))
            break;
        for(int col = 0; line[col] != '\0'; col++){
            if(line[col] == ' ')
                grid[row][col] = EMPTY;
            else
                grid[row][col] = (line[col] - '0');
        }
        row++;
    }
    gridFile.close();
}

/*int main(int argc, char* argv[]){
    if(argc != 2)
        return 0;
    readFile(argv[1], grid);
    int grid[N][N] = {{1,5,0,0,0,0,0,4,0},
                      {8,0,0,0,4,0,3,5,9},
                      {0,0,0,6,2,0,0,7,0},
                      {0,0,3,9,0,6,0,0,0},
                      {0,7,5,0,0,0,6,9,0},
                      {0,0,0,2,0,8,5,0,0},
                      {0,2,0,0,6,4,0,0,0},
                      {3,9,6,0,8,0,0,0,2},
                      {0,4,0,0,0,0,0,6,3}};

    printGrid(grid);
    cout << endl;
    if(solveSudoku(grid))
        printGrid(grid);
    else
        cout << "Soluzione non trovata" << endl;
    return 0;
}*/
