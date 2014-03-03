#include <iostream>
#include <queue>
using namespace std;

struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
      return l > r;  
  }  
};  
  
int main()  
{  
	cout.setf(ios::fixed);
	cout.precision(4);
	//priority_queue<int,vector<int>, greater<int> > pq; //cobos
    priority_queue<int,vector<int>, compare > pq;  
    string opc;
	int num;
	int sum = 0;
	int max = 0;
	bool prim = true;
	while(cin >> opc) {
			if(opc == "size") cout << pq.size() << endl;
			if(opc == "number") {
				cin >> num;				
				if(prim || num > max) {
					max = num;
 					prim = false;
				}
				
				pq.push(num);
				sum += num;
			}
			if(opc == "delete") {
				if(not pq.empty()) {
					sum -= pq.top();
					pq.pop(); 
				}
			}

		if(not pq.empty()) {
			cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: "  <<  ((double)sum/(double)pq.size()) << endl;
		}
		else {
			cout << "no elements" << endl;
			prim = true;
			sum = 0;
		}
		
	}
		
}


