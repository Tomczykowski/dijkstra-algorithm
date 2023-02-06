#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "FileIO.h"
#include "DijkstraAlgorithm.h"

using namespace std;


int main()
{
    vector<vector<int>> matrix;
    string filename = R"(C:\Users\wojte\CLionProjects\aisdgrafysekulatomczykowskipon8\BoardFiles\Board_2.txt)";
    ReadFileToVector(&matrix, filename);

    vector<vector<int>> dst = shortest(matrix);
    std::vector<std::pair<int, int>> zerosPos = GetZerosPos(matrix);
    int start_x = zerosPos[0].first;
    int start_y = zerosPos[0].second;
    int end_x = zerosPos[1].first;
    int end_y = zerosPos[1].second;

    printRoute(dst, matrix, start_x, start_y, end_x, end_y);
    return 0;
}