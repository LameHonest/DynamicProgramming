#include <fstream>
#include "stdio.h"
#include <algorithm>
#include <iostream>
using namespace std;

long countWays(int distance, int currentStep, int steps, int ways[37][50]) {
	if (distance == 0) {
		if (currentStep == steps) return 1;
		else return 0;
	}
	if (currentStep + distance <= steps) {
		if (ways[distance][currentStep] == 0) {
			ways[distance][currentStep] += countWays(distance - 1, currentStep + 1, steps, ways);
			ways[distance][currentStep] += countWays(distance + 1, currentStep + 1, steps, ways);
		}
	}
	cout << ways[distance][currentStep]<<endl;
	return ways[distance][currentStep];
}
int main() {
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int ways[37][50] = { 0 };
	int n, k;
	ifst >> n >> k;
	ofst << countWays(n, 0, k, ways);
	system("pause");
	return 0;
}