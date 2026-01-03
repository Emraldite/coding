#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// class symbols{
//     public:
//         vector<int> strong{};
//         vector<int> weak{};
//         vector<int> draw{};
//     void add_weak(int num){
//         weak.push_back(num);
//     } 
//     void add_strong(int num){
//         strong.push_back(num);
//     } 
//     void add_draw(int num){
//         draw.push_back(num);
//     }
// };


int main(){
    int symbols, games;
    cin>>symbols>>games;
    vector<vector<int>> eff(symbols);
    for (int i{}; i<symbols; i++){
        string effect;
        cin >> effect;
        for (int j{}; j<size(effect); j++){
            if (effect[j]=='W'){
                eff[j].push_back(i);
            }else if (effect[j]=='L'){
                eff[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < symbols; i++) {
        sort(eff[i].begin(), eff[i].end());
    }

    for (int i{}; i<games; i++){
        int l, r;
        cin >> l >> r;
        l-=1; r-=1;
        vector<int> result;
        set_intersection(eff[l].begin(), eff[l].end(), eff[r].begin(), eff[r].end(), back_inserter(result));
        cout<<symbols*symbols - (symbols-size(result))*(symbols-size(result)) << "\n";
    }
}