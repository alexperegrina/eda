#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<pair<int,bool> > p;
	while(cin >> n) {	
		pair<int,bool> px;
		px.first = n;
		px.second = true;
		p.push(px);
		while(not p.empty()){
			if(p.top().second == true) {
				if(p.top().first > 1) {
					px.first = p.top().first-1;
					px.second = true;	
					p.push(px);			
				}
				else {
					cout << " " << p.top().first; 
					p.pop();
					if(not p.empty()) p.top().second = false;
				}
			}
			else {
				n = p.top().first;
				cout << " " << n ;
				p.pop();
				px.first = n-1;
				px.second = true;
				p.push(px);	
			}
		}
		cout << endl;
	}
}
