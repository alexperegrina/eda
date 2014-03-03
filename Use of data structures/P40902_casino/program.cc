#include <iostream>
#include <map>

using namespace std;

typedef pair<string,int> Jugador; //first nom, second diners

int main() {
	string nom,accio;
	int d;
	map<string,int> casino;
	while(cin >> nom >> accio) {
		
		if(accio == "enters") {
			pair<map<string,int>::iterator ,bool> p = casino.insert(Jugador(nom,0));
			if(not p.second) cout << nom << " is already in the casino" << endl;
		}
		else if(accio == "wins") {
			cin >> d;
			map<string,int>::iterator it = casino.find(nom);
			if(it != casino.end()) it->second += d; 
			else cout << nom << " is not in the casino" << endl;
		}
		else if(accio == "leaves") {
			map<string,int>::iterator it = casino.find(nom);
			if(it != casino.end()) {
				cout << nom << " has won " << it->second << endl;
				casino.erase(nom);
			}
			else cout << nom << " is not in the casino" << endl;
		}		
			
	}
	cout << "----------" << endl;
	map<string,int>::iterator it = casino.begin();
	while(it != casino.end()) {
		cout << it->first << " is winning " << it->second << endl;
		++it;
	}
}
