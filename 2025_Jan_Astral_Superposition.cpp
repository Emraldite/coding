#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i{}; i<t; i++){
        int n, a, b;
        cin >>n>>a>>b;
        vector<vector<int>> initial(n, vector<int>(n, 0));
        vector<vector<int>> big(n, vector<int>(n, 0));
        // cout<<n<<a<<b;
        int possible=true;
        // for(vector<int> x: initial){
        //     for (int y: x){
        //         cout<<y;
        //     }
        //     cout<<'\n';
        // }
        for(int j{};j<n;j++){
            string row;
            cin>>row;
            
            for (int k{};k<n;k++){
                // cout <<j<<k<<a<<b<<'\n';
                big[j][k]=row[k];
                switch(row[k]){
                    case 'G':
                        if(k<a||j<b){
                            initial[j][k]=1;
                        }
                        else if(initial[j-b][k-a]==0){
                            initial[j][k]=1;
                            // final[j][k]=1;     FINAL NOT USED
                        }
                        break;
                    case 'B':
                        initial[j][k]=1;
                        if (j>=b&&k>=a){
                            if(big[j-b][k-a]=='G'||big[j-b][k-a]=='B'){
                                initial[j-b][k-a]=1;
                            }else{
                                possible=false;
                            }
                        }else{
                                possible=false;
                        }
                        break;
                        // final[j][k]=1;     FINAL NOT USED
                    // case 'W':              WHITE NOT USED
                        // initial[j][k]=0;     INITAL ALREADY 0;
                        // final[j][k]=0;     FINAL NOT USED        
                }
                
            }
        }
        if (possible){        
            int total{};
            for (const vector<int>& row: initial){
                for(int num: row){
                    // cout<<num;
                    total+= num;
                }
                // cout<<'\n';
            }
            cout<<total<<'\n';
        }else{
            cout<<"-1\n";
        }
    }
}