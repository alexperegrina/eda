#include <iostream>
#include <vector>

using namespace std;

void escriure(vector<char> &v){
	for(int i = 0; i < int(v.size()); ++i) cout << v[i];
	cout << endl;
}

void back(vector<char> &conso,vector<char> &vocals,int i,vector<char> &paraula,vector<bool> &vist1,vector<bool> &vist2) {
	int n = paraula.size();
	if(i == n) escriure(paraula);
	else {
		for(int j = 0; j < paraula.size(); ++j) {
			
			if(j%2 == 0) { //vocal
				paraula[i] = conso[j/2];
				if(not vist1[j/2] and i%2 == 0) {
					vist1[j/2] = true;					
					back(conso,vocals,i+1,paraula,vist1,vist2);	
					vist1[j/2] = false;	
				}		
			}
			else {
				paraula[i] = vocals[j/2];
				if(not vist2[j/2] and i%2 != 0) {
					vist2[j/2] = true;				
					back(conso,vocals,i+1,paraula,vist1,vist2);		
					vist2[j/2] = false;
				}	
			}
		}	
	}
}

int main(){
	int n;
	cin >> n;
	vector<char> conso(n);
	vector<char> vocals(n);
	vector<char> paraula(n*2);
	for(int i = 0; i < n; ++i) cin >> conso[i];
	for(int i = 0; i < n; ++i) cin >> vocals[i];
	vector<bool>vist1(n,false);
	vector<bool>vist2(n,false);
	back(conso,vocals,0,paraula,vist1,vist2);
}
