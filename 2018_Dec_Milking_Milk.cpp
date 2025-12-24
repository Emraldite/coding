#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

	int c1, m1, c2, m2, c3, m3;
	fin >> c1 >> m1>> c2>> m2>> c3>> m3;
	int pour{};
	for (int i = 0; i < 100; i++) {
		if (i%3 == 0) {
			pour = min(m1, c2-m2);
			m1 -= pour;
			m2 += pour;
		}
		if (i%3 == 1) {
			pour = min(m2, c3 - m3);
			m2 -= pour;
			m3 += pour;
		}
		if (i%3==2) {
			pour = min(m3, c1 - m1);
			m3 -= pour;
			m1 += pour;
		}
	}
	fout << m1 << '\n' << m2 << '\n' << m3;
}
