## Description

This is a small college graph theory project. It contains implementation of greedy Welsh-Powell graph coloring algorithm and backtracking m-coloring algorithm.

## Solving Sudoku

Project demonstrates ability to represent sudoku as a graph and find its solution via m-coloring of graph in question. Sudoku is implemented as derived class of class Graph and uses
backtracking algorithm to find a solution. It is implemented recursively and is not recommended for sudokus larger than 9x9 due to time complexity of algorithm being O(m^n) in the worst case. Where
m is number of colors and n number of nodes. For those cases to be solvable in reasonable time it would require some heuristics and optimization to presented code.
