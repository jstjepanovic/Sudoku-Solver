#include "Backtracking.h"

bool Backtracking::backtrackColoring(int vertex, const int noColors, Graph &graph)
{
    int N = graph.getN();

    if (vertex == N)
        return true;

    if (graph.coloringArray[vertex].second != -1) 
        return backtrackColoring(vertex + 1, noColors, graph);

    for (int color = 1; color <= noColors; color++)
    {
        if (isSafe(vertex, color, graph)) {
            graph.coloringArray[vertex].second = color;

            if (backtrackColoring(vertex + 1, noColors, graph)) {
                return true;
            }

            graph.coloringArray[vertex].second = -1;
        }
    }

    return false;
}

bool Backtracking::isSafe(const int vertex, const int color, Graph &graph)
{
    int N = graph.getN();

    std::vector<std::vector<int>> adjacencyMatrix(graph.getAdjacencyMatrix());

    for (int i = 0; i < N; i++)
        if (adjacencyMatrix[vertex][i] == 1 && graph.coloringArray[i].second == color)
            return false;
    
    return true;
}