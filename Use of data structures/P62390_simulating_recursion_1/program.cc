#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

int main() {
	stack<int> p; 
	int n,x;
	while(cin >> n) {
		cout << " " << n ;
		--n;
		if(n > 0) {
			p.push(n);
			p.push(n);
		}
		while(not p.empty()) {
			x = p.top();
			p.pop();
			cout << " " << x ;
			--x;
			if(x >= 1) {
				p.push(x);
				p.push(x);			
			}
		}
		cout << endl;
	}	
}
