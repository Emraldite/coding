#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k, n, count{};
    fin >> k>> n;
    int trials[10][20];

    for (int i{}; i<k;i++){
        for (int j{}; j<n; j++){
            int cow;
            fin>>cow;
            trials[i][cow]=j;
        }
    }


    for(int i{1}; i<=n;i++){
        for(int j{1}; j<=n;j++){
            if(i==j){
                continue;
            }
            for(int l{}; l<k; l++){
                if (trials[l][i]>trials[l][j]){
                    break;
                }else if(l+1==k){
                    count++;
                }
            }
        }
    }
    fout<<count;
}