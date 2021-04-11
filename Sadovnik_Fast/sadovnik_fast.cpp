#include<iostream>
#include<fstream>
#include<string>
#include<vector>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
 
    int n_trees;
    ifst >> n_trees;
 
    vector<long long> a;
    a.push_back(3);
    for (int i = 1; i < n_trees; ++i) {
        a.push_back(a[i - 1] * 2);
    }
    ofst << a[n_trees - 1];
 
    return 0;
}