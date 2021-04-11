#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

enum Color { White, Blue, Orange };

void count(vector<Color>& trees, int cur_indx, int& count_var) {
    static const vector<Color> all_colors({ White, Blue, Orange });
    if (cur_indx >= trees.size()) {
        count_var++;
        return;
    }

    if (cur_indx == 0) {
        for (auto& color : all_colors) {
            trees[cur_indx] = color;
            count(trees, cur_indx + 1, count_var);
        }
    }
    else {
        for (auto& color : all_colors) {
            if (trees[cur_indx-1] != color) {
                trees[cur_indx] = color;
                count(trees, cur_indx + 1, count_var);
            }
        }
    }
}
int main(int argc, char* argv[]) {
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");

    int n_trees;
    int count_coliring = 0;
    vector<Color> trees;

    ifst >> n_trees;

    trees.resize(n_trees);
    
    count(trees, 0, count_coliring);
    cout << count_coliring;
    ofst << count_coliring;
}