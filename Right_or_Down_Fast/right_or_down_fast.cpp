#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n, m;
    ifst >> n >> m;
    int** a = new int* [n]; // 
    for (int count = 0; count < n; count++)
        a[count] = new int[m]; //
    int** b = new int* [n]; // две строки в массиве
    for (int count = 0; count < n; count++)
        b[count] = new int[m]; //
        
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            b[i][j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            ifst >> a[i][j];
    }
    b[n - 1][m - 1] = 1;
    for (int i = m - 2; i >= 0; --i) {
        if (a[n - 1][i] <= m - 1 - i && b[n - 1][i + a[n - 1][i]] != 0)
            b[n - 1][i] = 1;
    }
    for (int i = n - 2; i >= 0; --i)
        if (a[i][m - 1] <= n - 1 - i && b[i + a[i][m - 1]][m - 1] != 0)
            b[i][m - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            if (a[i][j] <= n - 1 - i && b[i + a[i][j]][j] && a[i][j] <= m - 1 - j && b[i][j + a[i][j]])
                b[i][j] = b[i][j + a[i][j]] + b[i + a[i][j]][j];
            else
                if (a[i][j] <= n - 1 - i && b[i + a[i][j]][j])
                    b[i][j] = b[i + a[i][j]][j];
                else
                    if (a[i][j] <= m - 1 - j && b[i][j + a[i][j]])
                        b[i][j] = b[i][j + a[i][j]];

        }
    }
    ofst << b[0][0];
    for (int count = 0; count < n; count++)
        delete[]a[count];
    for (int count = 0; count < n; count++)
        delete[]b[count];
    return 0;
}