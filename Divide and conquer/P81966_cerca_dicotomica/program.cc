#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return -1;
	else {
		int i = (esq + dre)/2;
		if (x > v[i]) return posicio(x,v,i + 1,dre);
		if (x < v[i]) return posicio(x,v,esq,i - 1);
		else return i;
	}
}
