#include <fstream>
#include "stdio.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int len(vector<int> coord, int index) {
    if (index == 0)
        return 100000;
    else if (index == 1)
        return 0;
    else if (index == 2)
        return coord[1] - coord[0];
    else if (index == 3)
        return coord[2] - coord[0];
    if (index > 3)
    {
        return min(len(coord, index - 1), len(coord, index - 2)) + coord[index-1] - coord[index - 2];
    }
}

int main()
{
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n, buf;
    ifst >> n;
    vector<int> coord;
    for (int i = 0; i < n; ++i) {
        ifst >> buf;
        coord.push_back(buf);
    }
    sort(coord.begin(), coord.end());
    ofst << len(coord, n);
    return 0;
}