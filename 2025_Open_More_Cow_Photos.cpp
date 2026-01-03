#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int trials, cows;
    cin >> trials;
    for (int i{}; i<trials; i++){
        
        cin>>cows;
        vector<int> heights {};
        for (int j{};j<cows; j++){
            int cow_height;
            cin >> cow_height;
            heights.push_back(cow_height);
        }

        sort(heights.begin(), heights.end());

        int ans{1};
        heights.erase(std::remove(heights.begin(), heights.end(), heights.back()), heights.end());
        int previous{};
        for (int j{}; j+1<size(heights); j++){
            if(heights[j]==heights[j+1]&&heights[j]!=previous){
                previous=heights[j];
                ans+=2;
                j++;
            }
        }
        cout<<ans << "\n";
    }

}