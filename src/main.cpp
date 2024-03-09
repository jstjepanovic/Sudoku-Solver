#include <iostream>
#include "Graph.h"
#include "WelshPowell.h"
#include "Backtracking.h"

int main(){
    int noNumbers;

    std::cin >> noNumbers;

    std::vector<std::vector<int>> sudokuBoard(noNumbers, std::vector<int>(noNumbers));

    for (int i = 0; i < noNumbers; i++)
        for (int j = 0; j < noNumbers; j++)
            std::cin >> sudokuBoard[i][j];

    Sudoku sudoku(sudokuBoard);
    
    sudoku.Solve();

    return 0;
}