#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <fstream>

using namespace std;

int maxl(int i, int* mas, int n) {
	if (i > n - 3)
		return 0;
	return mas[i + 1] - mas[i] + max(maxl(i + 2, mas, n), maxl(i + 3, mas, n));
}

void selectionSort(int data[], int lenD)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < lenD; i++) {
		j = i;
		for (int k = i; k < lenD; k++) {
			if (data[j] > data[k]) {
				j = k;
			}
		}
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
}

int main(int argc, char* argv[]) {
	ifstream ifstr("input.txt");
	ofstream ofstr("output.txt");
	int n;
	ifstr >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		ifstr >> mas[i];
	selectionSort(mas, n);
	int m = max(maxl(1, mas, n), maxl(2, mas, n));
	cout << mas[n - 1] - mas[0] - m;
}