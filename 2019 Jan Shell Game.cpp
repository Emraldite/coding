#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int number;
    int maxC = 0;
    fin >> number;
    vector<int> a(number), b(number), g(number);
    for (int i = 0; i < number; i++) {
        fin >> a[i] >> b[i] >> g[i];
    }
    for (int q = 1; q < 4; q++) {
        int p = q;
        int count = 0;
        for (int i = 0; i < number; i++) {
            if (p == a[i]) {
                p = b[i];
            }
            else if (p == b[i]) {
                p = a[i];
            }
            if (p == g[i]) {
                count++;
            }
        }

        if (count > maxC) {
            maxC = count;

        }
    }
    fout << maxC;
}
