#include <fstream>
#include "stdio.h"
#include <algorithm>
#pragma warning(disable : 4996)   // чтобы машина не ругалась за устаревший ввод
using namespace std;

int n, i;
int a[10001], b[10001];
long long e, f, g;

void sort(int l, int r) { // быстрая сортировка по возрасту
    int i, j, x, w;
    i = l;
    j = r;
    x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            i++; j--;
        }
    } while (i < j);
    if (l < j) sort(l, j);
    if (i < r) sort(i, r);
    return;
}

int main() {
   
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n;
    ifst >> n;
      // число агентов
    for (int i = 1; i <= n; i++) ifst >> a[i] >> b[i];
    sort(1, n);  // быстрая сортировка по возрасту
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