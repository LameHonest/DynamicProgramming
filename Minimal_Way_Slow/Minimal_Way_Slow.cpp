#include <fstream>
#include <iostream>



using namespace std;
bool IsAvailable(int x, int y, int n,int m)
{
    if ((x >= 0) && (x < n) && (y >= 0) && (y < m))
        return true;

    return false;
}

int FindPath(int** a, int n,int m, int x, int y, int sum)
{
    static int minSum = -1; //минимальная сумма путей

    //если текущие координаты совпадают с концом пути,то
    //пересчитываем минимальную сумму
    if ((x == (n - 1)) && (y == (m - 1)))
    {
        if ((minSum < 0) || (sum < minSum)) //если текущая сумма меньше минимальной,то запоминаем ее
            minSum = sum;
    }

    if (IsAvailable(x + 1, y, n,m)) //рекурсивный вызов для соседнего элемента справа
        FindPath(a, n,m, x + 1, y, sum + a[x + 1][y]);

    if (IsAvailable(x, y + 1, n,m))  //рекурсивный вызов для соседнего элемента снизу
        FindPath(a, n,m, x, y + 1, sum + a[x][y + 1]);

    

    return minSum;
}
int main() {
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n, m,x,y,sum;
    ifst >> n >> m;
    int** a = new int* [n]; 
    for (int x = 0; x < n; x++)
        a[x] = new int[m];

    for (int x = 0; x < n; ++x) {
        for (int y = 0;y < m; ++y) {
            ifst >> a[x][y];
        }
    }
    x = 0; y = 0, sum = a[0][0];
    FindPath(a, n, m,x, y, sum);
   
    
        ofst << FindPath(a, n,m, x, y, sum) << endl;
    for (int count = 0; count < n; count++)
        delete[]a[count];
   
    return 0;
}