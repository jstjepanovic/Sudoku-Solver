#include "WelshPowell.h"

std::vector<std::pair<int, int>> WelshPowell::coloringSequential(Graph &graph)
{
    std::vector<std::vector<int>> adjacencyMatrix(graph.getAdjacencyMatrix());

    std::vector<std::pair<int, int>> degreeArray(graph.getDegreeArray());

    int N = graph.getN();

    std::sort(degreeArray.begin(), degreeArray.end(), compareDegree);

    for (int i = 0; i < N; i++)
    {
        int vertex = degreeArray[i].first;

        if (graph.coloringArray[vertex].second == -1){
                    std::vector<bool> usedColors(N, false);

            for (int j = 0; j < N; j++)
            {
                if (adjacencyMatrix[vertex][j] == 1 && graph.coloringArray[j].second != -1)
                    usedColors[graph.coloringArray[j].second - 1] = true;
            }

            for (int c = 0; c < N; c++)
            {
                if (!usedColors[c])
                {
                    graph.coloringArray[vertex].second = c + 1;
                    break;
                }
            }   
        }

    }

    return graph.coloringArray;
}


bool WelshPowell::compareDegree(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second > b.second;
}