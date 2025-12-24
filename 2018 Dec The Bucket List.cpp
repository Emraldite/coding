#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>   
using namespace std;

int main() {
    int number;
    int s{}, e{}, g{};
    ifstream fin("blist.in");
    ofstream fout("blist.out");

    array<int, 1000> arr = {};
    fin >> number;

    for (int i = 0; i < number; i++) {
         fin >> s >> e >> g;
        for (int j = s; j <= e; j++) {
            arr[j] += g;
        }
    }
    fout << *std::max_element(arr.begin(), arr.end());

}
