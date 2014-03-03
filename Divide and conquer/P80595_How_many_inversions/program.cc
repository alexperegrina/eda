#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v,int e, int m, int d, int &s) {
	vector<int> b(d-e+1);
	int i = e;
	int j = m+1;
	int k = 0;
	while(i <= m and j <= d) {
		if(v[i] <= v[j]) b[k++] = v[i++];
		else {
			b[k++] = v[j++];
			s += (m-i+1);
		}
	}
	while (i <= m) b[k++] = v[i++];
	while (j <= d) b[k++] = v[j++];
	for(k = 0; k <= d-e; ++k) v[e+k] = b[k];
	
}

void merge_sort_i(vector<int> &v,int e,int d,int &s) {
	if(e < d) {
		int m = (e+d)/2;
		merge_sort_i(v,e,m,s);
		merge_sort_i(v,m+1,d,s);
		merge(v,e,m,d,s);
	}
}

void merge_sort(vector<int> &v,int &s) {
	merge_sort_i(v,0,v.size()-1,s);
}

int main() {
	int i;
	int s;
	while(cin >> i) {
		s = 0;
		vector<int> v(i);
		for(int j = 0; j < i; ++j) cin >> v[j];
		merge_sort(v,s);
		cout << s << endl;
	}	
}
