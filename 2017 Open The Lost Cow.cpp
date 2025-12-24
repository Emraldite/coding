
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ifstream fin("lostcow.in");
	ofstream fout("lostcow.out");
	int x, y;
	fin >> x >> y;
	int d{ y - x };
	int t{};
	int c{ 1 };
	for (c; (c < d && d > 0) || (c > d && d < 0); c *= -2) {
		t += abs(c) + abs(c / 2);
	}
	t += abs(c / 2) + d;
	cout << t;


}


