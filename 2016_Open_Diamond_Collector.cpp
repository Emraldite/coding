#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n, k;
    fin>>n>>k;
    vector<int> sizes{};
    for (int i{}; i<n; i++){
        int dia;
        fin>>dia;
        sizes.push_back(dia);
    }
    sort(sizes.begin(), sizes.end());
    queue<int> q{};
    q.push(sizes[0]);
    int maxSize{1};
    for (int i{1}; i<size(sizes); i++){
        q.push(sizes[i]);

        while (!q.empty() && q.back() - q.front() > k) {
            q.pop();
        }

        maxSize = max(maxSize, (int)q.size());
    }
    fout<<maxSize;
}