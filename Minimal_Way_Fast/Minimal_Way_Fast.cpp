#include <fstream>
#include <vector>

using namespace std;
struct Cell {
    int value;
    int pathCost;
};
int main() {
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n, m;
    ifst >> n >> m;
    vector<vector<Cell>> a(n, vector<Cell>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ifst >> a[i][j].value;
        }
    }
    a[0][0].pathCost = a[0][0].value;
    for (int i = 1; i < n; ++i) {
        a[i][0].pathCost = a[i][0].value + a[i - 1][0].pathCost;
    }
    for (int i = 1; i < m; ++i) {
        a[0][i].pathCost = a[0][i].value + a[0][i - 1].pathCost;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            a[i][j].pathCost = min(a[i - 1][j].pathCost, a[i][j - 1].pathCost) + a[i][j].value;
        }
    }
    ofst << a[n - 1][m - 1].pathCost << endl;
}