#include <fstream>
#include "stdio.h"
#include <algorithm>
#include <iostream>
using namespace std;

void sort(int* a,  int* b, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            if (a[j - 1] > a[j])
            {
                int temp = a[j - 1];
                int temp1 = b[j - 1];
                a[j - 1] = a[j];
                b[j - 1] = b[j];
                a[j] = temp;
                b[j] = temp1;
            }
        }
    }
}

int main() {


    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n;
    ifst >> n;
    int* a = new int[n];
    int* b = new int[n];
    long long e, f, g;
    // число агентов
    for (int i = 1; i <= n; i++) ifst >> a[i] >> b[i];
    sort(a,b, n);
    e = b[2];
    f = b[2] + b[3]; // считаем риск провала
    for (int i = 4; i <= n; i++) { // ищем минимальный, двигаясь снизу вверх
        if (e < f) g = e;
        else g = f;
        g = g + b[i];
        e = f;
        f = g;
    }
    if (n == 2) ofst << e;
    else ofst << f;
    return 0;
}
