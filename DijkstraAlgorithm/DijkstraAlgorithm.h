#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "FileIO.h"

using namespace std;

struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) :
            x(x), y(y), distance(distance) {}
};

bool operator<(cell const& a, cell const&b);
bool isInsideGrid(int i, int j, int width, int height);
vector<vector<int>> shortest(vector<vector<int>> &matrix);
void printRoute(vector<vector<int>> &distMatrix, vector<vector<int>> &grid, int &start_x, int &start_y, int &end_x, int &end_y);
pair<int, int> findMinVertex(vector<vector<int>> &distMatrix, int &pos_x, int &pos_y);