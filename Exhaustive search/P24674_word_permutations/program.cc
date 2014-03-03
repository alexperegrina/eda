#include <iostream>
#include <vector>
using namespace std;
 
void back(vector<string> &par,vector<string> &permut, int i, vector<bool> &vistes) {
	if(i == par.size()) {
		cout << "(";
		for(int j = 0; j < permut.size(); ++j) {
			cout << permut[j];
			if(j != permut.size()-1) cout << ",";		
			
		}
		cout << ")" << endl;
	}
	else {
		for(int j = 0; j < par.size(); ++j) {
			if(not vistes[j]) {
				vistes[j] = true;
				permut[i] = par[j];	
				back(par,permut,i+1,vistes);
				vistes[j] = false;		
			}		
			
		}
	}
}

int main()
{
    int n;
    cin >> n;
    vector<string> paraules(n);
	vector<string> permut(n);
    vector<bool> vistes(n,false);
    for (int i = 0; i < n; ++i) cin >> paraules[i];
    back(paraules, permut, 0, vistes);
}

