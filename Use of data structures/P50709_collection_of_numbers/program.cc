#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	priority_queue<int> pq;
	char c;
	int num,sum;
	while(cin >> c) {
		switch(c) {
			case 'S':
				cin >> num;
				pq.push(num);
				break;		
			case 'A':
				if(pq.empty()) cout << "error!" << endl;
				else cout << pq.top() << endl;
				break;
			case 'R':
				if(pq.empty()) cout << "error!" << endl;
				else pq.pop();
				
				break;
			case 'I':
				cin >> sum;
				if(pq.empty()) cout << "error!" << endl;
				else {
					num = pq.top()+sum;
					pq.pop();
					pq.push(num);	
				}
				
				break;
			case 'D':
				cin >> sum;
				if(pq.empty()) cout << "error!" << endl;
				else {
					num = pq.top()-sum;
					pq.pop();
					pq.push(num);	
				}
				break;
		}
	}
}
