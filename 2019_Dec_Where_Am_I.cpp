#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fin("whereami.in");
    fstream fout("whereami.out");
    int n{};
    fin >> n;


    string word{};
    fin >> word;
    bool found{ false };
    for (int l = 1; l < n; l++) {
        found = false;
        for (int i = 0; i < n; i++) {
            string part = word.substr(i, l);
            for (int j = i + 1; j < n; j++) {
                string part2 = word.substr(j, l);
                if (part == part2) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            cout << l;
            break;
        }
    }
}