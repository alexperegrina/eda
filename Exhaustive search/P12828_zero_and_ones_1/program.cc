#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> VE;

VE v;
int n;

void func(int i) {
	if(i == n) {
		bool primer = true;
		for(int j = 0; j < n; ++j) {
			if(primer) primer = false;		
			else	cout << " ";
			cout << v[j];
		}
		cout << endl;
	}
	else {
		v[i] = 0;
		func(i+1);
		v[i] = 1;
		func(i+1);	
	}
}

int main() {
	cin >> n;
	v = VE(n);
	func(0);
}
