#include <iostream>
#include <vector>
using namespace std;

struct node {
	char valor;
	int num;
};
typedef vector<vector<node> > MatriuNod;
typedef vector<vector<int> > MatriuInt;
typedef vector<vector<bool> > MatriuBool;

MatriuInt convert_mat_to_listAdj(MatriuNod &map,int &n, int &m) {
	MatriuInt listad(n*m);
	int pos;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(map[i][j].valor != 'X') {
				pos = map[i][j].num;
				if(i != 0 and map[i-1][j].valor != 'X') listad[pos].push_back(map[i-1][j].num);
				if(j != 0 and map[i][j-1].valor != 'X') listad[pos].push_back(map[i][j-1].num);
				if(i != (n-1) and map[i+1][j].valor != 'X') listad[pos].push_back(map[i+1][j].num);
				if(j != (m-1) and map[i][j+1].valor != 'X') listad[pos].push_back(map[i][j+1].num);
			}
		}
	}
	return listad;
}

void print(MatriuInt &l,int x) {
	int cont = 0;
	int size;
	for(int i = 0; i < x; ++i) {
		cout << "nodo: "<< cont << " ---- ";
		size = l[i].size();
		for(int j = 0; j < size; ++j) {
			cout << l[i][j] << " "; 
		}
		cout << endl;
		++cont;
	}
}

void hay_tesoro_i(MatriuInt & graf, vector<bool> &tres,int u, vector<bool>& vist,bool &tresor) {
	if(not vist[u]) {
		int size = graf[u].size();
		/*int m = p.second[0].size();
		int c = (u-1)%m;
		int r = ((u-1)-c/m);*/
		if(tres[u]) tresor = true;
		vist[u] = true; 
		int i = 0;
		while(i < size and not tresor) {
			hay_tesoro_i(graf,tres,graf[u][i],vist,tresor);
			++i;
		}
	}
}


bool hay_tesoro(MatriuInt & graf, vector<bool> &tres,int u) {
	int n = graf.size();
	vector<bool> vis(n,false);
	bool tresor = false;
	hay_tesoro_i(graf,tres,u,vis,tresor);
	return tresor;
}


int main() {
	int n,m,c,r;
	int cont = 0;
	cin >> n >> m;
	MatriuNod map(n,vector<node>(m));
	MatriuInt listad;
	pair<MatriuInt,MatriuBool> p;
	vector<bool> tres = vector<bool>(n*m,false);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >>map[i][j].valor;
			if(map[i][j].valor == 't') tres[cont] = true;
			map[i][j].num = cont; 
			++cont;
		}
	}
	listad = convert_mat_to_listAdj(map,n,m);
	cin >> c >> r;
	if(hay_tesoro(listad,tres,map[c-1][r-1].num)) cout << "yes" << endl;
	else cout << "no" << endl;
	
}
