#include <iostream>
#include <vector>
using namespace std;

int first_occurrence_i(double z, const vector<double> &v, int esq, int dre) {
	if(esq > dre) return -1;
	else {
		int m = (esq + dre)/2;
		if(z < v[m]) return first_occurrence_i(z,v,esq,m-1);
		if(z > v[m]) return first_occurrence_i(z,v,m+1,dre);
		if(m == 0 or z > v[m-1]) return m;
		return first_occurrence_i(z,v,esq,m-1);
	}
}

int first_occurrence(double x, vector<double>& v) {
	return first_occurrence_i(x,v,0,v.size()-1);
}

int main () {
	int n;
	cin >>n;
	vector<double> v(n);
	for (int i=0; i<n; i++) cin>>v[i];
	double x;
	cin >> x;
	cout<< first_occurrence(x,v)<<endl;
}
