#ifndef GRAPH_H
#define GRAPH_H

#include "Backtracking.h"
#include <vector>
#include <iostream>
#include <cmath>


class Graph{
protected:
    int N;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<std::pair<int, int>> degreeArray;

public:
    std::vector<std::pair<int, int>> coloringArray;

    Graph();

    Graph(const std::vector<std::vector<int>> &adjacencyMatrix);

    ~Graph();

    int getN();

    std::vector<std::vector<int>> getAdjacencyMatrix();
    
    std::vector<std::pair<int, int>> getDegreeArray();

};

class Sudoku : public Graph{
protected:
    int boxSize;
    int noNumbers;

public:
    Sudoku(const std::vector<std::vector<int>> &sudokuBoard);

    ~Sudoku();

    void Solve();

};

#endif