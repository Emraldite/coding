#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>  
#include <algorithm> 
using namespace std;

int timeSolve(const vector<int>& d, int k);

int main() {
    ifstream fin ("cowdance.in");
    ofstream fout ("cowdance.out");

    int n{};
    int maxt{};
    fin >> n >> maxt;
    vector<int> d{};

    for (int i = 0; i < n; i++) {
        int v;
        fin >> v;
        d.push_back(v);
    }

    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (timeSolve(d, mid) <= maxt) {
            ans = mid;    // This k works, but a smaller one might too
            high = mid - 1;
        } else {
            low = mid + 1; // Too slow, must increase stage size
        }
    }
    fout<<ans;
}

int timeSolve(const vector<int>& d, int k){
    vector<int> l (k,0);
    for (int x: d){
        *min_element(l.begin(), l.end())+=x;
    }
    return *max_element(l.begin(), l.end());
}