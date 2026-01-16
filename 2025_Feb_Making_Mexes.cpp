#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> b(n+1);
    for (int i{}; i<n; i++){
        int add;
        cin>>add;
        b[add]++;
    }
    int pre{};
    for(int i{}; i<=n;i++){
        int change{};
        // // //zero value i
        // change+= b[i];

        // //none before
        // int zchange{};
        // for (int j{};j<i; j++){
        //     if (b[j]==0){
        //         zchange++;
        //     }
        // }
        // cout<<max(change,zchange)<<'\n';



        change=max(b[i], pre);
        if (b[i]==0){   
            pre++;
        }
        cout<<change<<'\n';
    }

}