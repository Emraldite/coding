#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    int num;
    fin >> num;
    int count{};
    
    for(int i{1}; ; i++){
        if ((i%5!=0&&i%3!=0)){
            count++;
            if (count==num){
                fout<<i;
                break;
            }
        }
    }
}


//Alternate Mathmatical Solution (faster)
#include <vector>

int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    int num;
    fin >> num;
    vector<int> pattern = {1, 2, 4, 7, 8, 11, 13, 14};
    int repeats = (num-1)/8;

    fout<<(repeats*15 + pattern[(num%8-1)]);
}