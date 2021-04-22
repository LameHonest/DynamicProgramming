#include <iostream>
#include <fstream>
#include "stdio.h"
#include <algorithm>


using namespace std;

void countWays(int distance, int steps, int &ways) {
	//cout << "Distance = " << distance << "; Steps = " << steps << endl;
	//Если человек в магазине и у него не осталось шагов
	if (distance == 0 && steps == 0) {
		ways++; //Нашли ещё один путь в магазин+
	}
	//Со старта назад можно, а вот доходить до магазина раньше К-го шага нельзя
	if (distance != 0 && steps > 0) {
		//Если не кончилось кол-во шагов
		if (steps - 1 >= 0) {
	    //Идём к магазину
		countWays(distance - 1, steps - 1, ways);
		//Идём от магазина
		countWays(distance + 1, steps - 1, ways);
		}
	}
}

int main() {
	unsigned int start_time = clock();
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, k;
	in >> n >> k;
	int ways = 0;
	countWays(n, k, ways);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Time = " << search_time/1000.0 << " sec" << endl;
	out << ways;
	system("pause");
	return 0;
}