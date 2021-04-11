#include <iostream>
#include <string>
#include <fstream>
using namespace std;

long long  a[71][71];
long long s = 0;
int n, m;
void p(int i, int j) {
    if (i + a[i][j] <= n) {
        if (a[i + a[i][j]][j] == 0) { s++; return; }
        else p(i + a[i][j], j);
    }
    if (j + a[i][j] <= m) {
        if (a[i][j + a[i][j]] == 0) { s++; return; }
        else p(i, j + a[i][j]);
    }
    return;
}

int main() {
    ifstream ifstr("input.txt");
    ofstream ofstr("output.txt");
    ifstr >> n >> m;
    for (int z = 1; z <= n; z++)
        for (int x = 1; x <= m; x++) ifstr >> a[z][x];
    p(1, 1);
    ofstr << s;
    return 0;
}