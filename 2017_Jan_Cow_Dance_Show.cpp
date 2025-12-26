#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>  
#include <algorithm> 
#include <queue>
using namespace std;

// int timeSolve(const vector<int>& d, int k);
int heapTimeSolve(const vector<int>& d, int k);
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
        if (heapTimeSolve(d, mid) <= maxt) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }
    fout<<ans;
}

// int timeSolve(const vector<int>& d, int k){
//     vector<int> l (k,0);
//     for (int x: d){
//         *min_element(l.begin(), l.end())+=x;
//     }
//     return *max_element(l.begin(), l.end());
// }
int heapTimeSolve(const vector<int>& d, int k){
    priority_queue<int, vector<int>, greater<int>> minPq;
    int offset{};
    
    for(int i{}; i<k; i++){
        minPq.push(d[i]);
    }
    for(int i{k}; i<d.size(); i++){
        offset=minPq.top();
        minPq.pop();
        minPq.push(d[i]+offset);
    }

    int ans{};
    while(!minPq.empty()){
        ans = max(minPq.top(), ans);        
        minPq.pop();
    }

    return ans;
}