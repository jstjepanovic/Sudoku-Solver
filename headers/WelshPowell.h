#ifndef WELSH_POWELL_H
#define WELSH_POWELL_H

#include "Graph.h"
#include <algorithm>

class WelshPowell
{
private:
    static bool compareDegree(const std::pair<int, int> &a, const std::pair<int, int> &b);

public:
    static std::vector<std::pair<int, int>> coloringSequential(Graph &graph);
};



#endif