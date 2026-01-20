#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long count{}, n;
    cin >>n;
    vector<vector<int>> nums(n);
    // vector<int> original{};
    vector<int> unique{};
    vector<char> notSeen(n, 1);
    int uniqueCt{-1};
    for (long long i{}; i<n; i++){
        long long add;
        cin>>add;
        // original.push_back(add);
        nums[add].push_back(i);
        if(notSeen[add]){
            notSeen[add]=0;
            uniqueCt++;
            unique.push_back(uniqueCt);
        }else{
            unique.push_back(uniqueCt);
        }
    }
    
    // int lim = nums[j][nums[j].size() - 2];
    // for(long long i{}; i<lim; i++){
    //     int v = original[i];
    //     if (v!=j&&notSeen[v]){
    //         count++;
    //         notSeen[v]=0;
    //     }
    // }


    for (long long j{}; j<n; j++){
        if(nums[j].size()>1){
            count+=unique[nums[j][nums[j].size() - 2]];
        }
    }
    cout<<count;

}