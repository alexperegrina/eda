#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct node {
	char valor;
	int num;
};
typedef vector<vector<node> > MatriuNod;
typedef vector< vector<int> > graph;

//funcion para convertir un grafo en una lista de adjecencias
graph convert_mat_to_listAdj(MatriuNod &map,int &n, int &m) {
	graph listad(n*m);
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

//por cada nodo pone la distancia minima ente un nodo inicial y todos los demas
vector<pair<int,int> > bfs (const graph& G,const vector<bool> &tresors,const int &u) {
	int n = G.size();
	pair<int,int> p;
	queue<pair<int,int> > Q;//first = valor, second = distancia.
	vector<bool> enc(n, false);
	vector<pair<int,int> > distres;//first = num, second = distancia
	int dis = -1;
	if (not enc[u]) {
		p.first = u; p.second = dis;
		Q.push(p);
		enc[u] = true;
		while (not Q.empty()) {
			p = Q.front(); Q.pop();
			int v = p.first;
			dis = p.second+1;
			if(tresors[v]) {
				pair<int,int> t; t.first = v; t.second = dis;		
				distres.push_back(t);	
			}
			for (int i = 0; i < G[v].size(); ++i) {
				pair<int,int> wp; wp.first = G[v][i]; wp.second = dis;
				if (not enc[wp.first]) {
					Q.push(wp); enc[wp.first] = true;
				}
			}
		}
	}
	return distres;
}

int main() {
	vector<pair<int,int> > distres;
	int n,m,c,r;
	int cont = 0;
	cin >> n >> m;
	MatriuNod map(n,vector<node>(m));
	graph G;
	vector<bool> tres = vector<bool>(n*m,false);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >>map[i][j].valor;
			if(map[i][j].valor == 't') tres[cont] = true;
			map[i][j].num = cont; 
			++cont;
		}
	}
	G = convert_mat_to_listAdj(map,n,m);
	cin >> c >> r;
	distres = bfs(G,tres,map[c-1][r-1].num);
	cout << distres.size() << endl;
	
}
