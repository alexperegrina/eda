#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int expm(int b,int e,int m) {
	if(e > 0) {
		int k = e/2;
		int r = expm(b,k,m);
		if(e%2 == 0) {
			return r%m*r%m;
		}
		else return r%m*r%m*b%m;
	}
	else if(e == 1) return b;
	else return 1;
}

int main() {
	int n,k,m;
	while(cin >> n >> k >> m) {
		cout << expm(n,k,m) << endl;
	}
}
