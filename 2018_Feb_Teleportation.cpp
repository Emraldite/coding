#include <iostream>
#include <fstream>
//include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int start, end, tpa, tpb;
    fin >> start >> end >> tpa >> tpb;
    fout << min(abs(end-start), min((abs(start-tpa)+abs(end-tpb)), (abs(start-tpb)+abs(end-tpa))));
}
