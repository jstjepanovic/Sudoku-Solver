#include "Graph.h"

Graph::Graph(){}

Graph::Graph(const std::vector<std::vector<int>> &adjacencyMatrix)
{
    Graph::adjacencyMatrix = adjacencyMatrix;
    Graph::N = adjacencyMatrix[0].size();

    for(int i=0; i<N; i++)
    {
        int degree = 0;

        for (int j=0; j<N; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
                degree++;
        }

        Graph::degreeArray.push_back(std::make_pair(i, degree));
        Graph::coloringArray.push_back(std::make_pair(i, -1));

    }
}

Graph::~Graph(){}

int Graph::getN()
{
    return this->N;
}

std::vector<std::vector<int>> Graph::getAdjacencyMatrix()
{
    return this->adjacencyMatrix;
}

std::vector<std::pair<int, int>> Graph::getDegreeArray()
{
    return this->degreeArray;
}

Sudoku::Sudoku(const std::vector<std::vector<int>> &sudokuBoard)
{
    Sudoku::noNumbers = sudokuBoard[0].size();
    Sudoku::N = noNumbers * noNumbers;
    Sudoku::boxSize = int(std::sqrt(noNumbers));
    
    Sudoku::adjacencyMatrix = std::vector<std::vector<int>> (N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        int degree = 0;

        int iRow = i / noNumbers;
        int iCol = i % noNumbers; 

        int boxStartRow = (iRow / boxSize) * boxSize;
        int boxStartCol = (iCol / boxSize) * boxSize;
        int boxEndRow = boxStartRow + boxSize - 1;
        int boxEndCol = boxStartCol + boxSize - 1;

        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                Sudoku::adjacencyMatrix[i][j] = 0;
                continue;
            }

            int jRow = j / noNumbers;
            int jCol = j % noNumbers;

            if (iRow == jRow || iCol == jCol)
            {
                Sudoku::adjacencyMatrix[i][j] = 1;
                degree++;
                continue;
            }

            if (jRow >= boxStartRow && jRow <= boxEndRow && jCol >= boxStartCol && jCol <= boxEndCol)
            {
                Sudoku::adjacencyMatrix[i][j] = 1;
                degree++;
                continue;
            }

            if (sudokuBoard[iRow][iCol] == sudokuBoard[jRow][jCol] && sudokuBoard[iRow][iCol] != -1)
            {
                Sudoku::adjacencyMatrix[i][j] = 1;
                degree++;
                continue;
            }

            Sudoku::adjacencyMatrix[i][j] = 0;
        }
        
        Sudoku::degreeArray.push_back(std::make_pair(i, degree));
        Sudoku::coloringArray.push_back(std::make_pair(i, sudokuBoard[iRow][iCol]));
        
    }
    
}

Sudoku::~Sudoku(){}

void Sudoku::Solve()
{
    if (!Backtracking::backtrackColoring(0, Sudoku::noNumbers, *this))
    {
        std::cout << "There is no possible solution for this sudoku.\n";
        return;
    }

    for (int i = 0; i < noNumbers; i++)
    {
        for (int j = 0; j < noNumbers; j++)
        {
            std::cout << Sudoku::coloringArray[i * noNumbers + j].second << " ";
        }

        std::cout << "\n";
    }
    
}
