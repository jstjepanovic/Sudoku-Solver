#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "Graph.h"

class Graph;

class Backtracking{
private:
    static bool isSafe(const int vertex, const int color, Graph &graph);

public:
    static bool backtrackColoring(int vertex, const int noColors, Graph &graph);

};

#endif