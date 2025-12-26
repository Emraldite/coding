#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCows(vector<int>field, int distanceAns);
int main(){
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    int cowAmount{}, patchAmount{};
    vector<int> field{};
    fin >> cowAmount >> patchAmount;
    for (int i{}; i<patchAmount*2; i++){
        int grassEdge{};
        fin >> grassEdge;
        field.push_back(grassEdge);
    }
    sort(field.begin(), field.end());
    int distanceMin{1};
    int distanceMax{field.back() - field[0]};
    int ans{distanceMax};
    while (distanceMin<=distanceMax){
        int mid{(distanceMin+distanceMax)/2};
        if(maxCows(field, mid)>=cowAmount){
            ans = mid;
            distanceMin=mid+1;
        }
        else{
            distanceMax=mid-1;
        }
    }
    fout<<ans;
}
int maxCows(vector<int>field, int distanceAns){
    int cowCount{0};
    int location{0-distanceAns-1};
    for (int i{}; i<field.size(); i+=2){
        if (location+distanceAns<=field[i]){
            location = field[i];
            cowCount++;
            int cowsAdded = (field[i+1]-location)/distanceAns;
            cowCount+=cowsAdded;
            location += cowsAdded*distanceAns;
        }else if(location+distanceAns>field[i+1]){
            continue;
        }else{
            int cowsAdded = (field[i+1]-location)/distanceAns;
            cowCount+=cowsAdded;
            location += cowsAdded*distanceAns;
        }
    }
    return cowCount;
}