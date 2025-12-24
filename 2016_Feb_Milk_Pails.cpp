#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int x, y, m;
    fin >> x >> y >> m;
    int biggest{};
    int numy{ m / y };
    for (int i = 0; i <= numy; i++) {
        biggest = max(((m - i * y) / x) * x + i * y, biggest);
    }
    fout << biggest;

}

