#include <iostream>
#include <vector>
using namespace std;
 
void back(vector<string> &par,vector<vector<string> > &conjt, int i, vector<bool> &vistes) {
	if(i == par.size()) {
		for(int j = 0; j < conjt.size(); ++j) {
			cout << "subconjunt " << j+1 << ": {";
			for(int k = 0; k < conjt[j].size(); ++k) {
				cout << conjt[j][k];
				if(k != conjt[j].size()-1) cout << ",";			
			}		
			cout << "}" << endl;
		}
		cout << endl;
	}
	else {
		for(int j = 0; j < conjt.size(); ++j) {
			if(not vistes[i]) {
				vistes[i] = true;
				conjt[j].push_back(par[i]);			
			}		
			back(par,conjt,i+1,vistes);
			vistes[i] = false;
			conjt[j].pop_back();
		}
	}
}

int main()
{
    int n, p;
    cin >> n;
    vector<string> paraules(n);
    vector<int> pos_par(n,0);
    vector<bool> vistes(n,false);
    for (int i = 0; i < n; ++i) cin >> paraules[i];
    cin >> p;
    vector <vector<string> > subconjunts(p);
    back(paraules, subconjunts, 0, vistes);
}



