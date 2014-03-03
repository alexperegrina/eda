#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ArcP;//first = node->v, second=dis
typedef vector< vector<ArcP> > GrafP;
// arc amb pes
// graf amb pesos
void dijkstra(const GrafP& G, int s, vector<int>& d, vector<int>& p, vector<int>& vecpath) {
	int n = G.size();
	d = vector<int>(n, 9999999); d[s] = 0;
	p = vector<int>(n, -1);
	vecpath = vector<int>(n, 0);
	vecpath[s] = 1;
	vector<bool> S(n, false);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
	Q.push(ArcP(0, s));
	while (not Q.empty()) {
		int u = Q.top().second; Q.pop();
		if (not S[u]) {
			S[u] = true;
			for (int i = 0; i < G[u].size(); ++i) {
				int v = G[u][i].second;
				int c = G[u][i].first; 
				//if (d[v] == d[u] + c) ++vecpath[v];
				if (d[v] > d[u] + c) {
					//++vecpath[v];
					d[v] = d[u] + c;
					p[v] = u;
					//vecpath[v] = vecpath[u] +1;
					//++vecpath[v];
					Q.push(ArcP(d[v], v));
					vecpath[v] = vecpath[u];
				}
				else if(d[v] == d[u] + c) {
					//if(vecpath[v] > vecpath[u] +1) vecpath[v] = vecpath[u] +1;
					vecpath[v] += vecpath[u];
				}
			}
		}
	}
}


void num_path(vector<int>& d,vector<int>& p,vector<int>& v,int &x,int &y) {
	
	/*if(p[y] != -1) cout << "cost " << d[y] << ", " << v[y] << " way(s)" << endl;
	else if(y == x) cout << "cost " << 0 << ", " << 0 << " way(s)" << endl;
	else cout << "no path from " << x << " to " << y << endl;*/
	if (d[y] != 9999999) {
		cout << "cost "<< d[y] <<", "<< v[y] << " way(s)" << endl;
	}
	else cout << "no path from " << x << " to " << y << endl;
}

int main() {
	int n,m,u,x,y;
	while(cin >> n >> m) {
		vector<int> d; //distancia
		vector<int> p; //predecesor
		vector<int> v; //diferentes caminos;
		GrafP G(n);
		ArcP arc;
		for(int i = 0; i < m; ++i) {
			cin >> u >> arc.second >> arc.first;
			G[u].push_back(arc);
		}
		cin >> x >> y;
		dijkstra(G,x,d,p,v);
		num_path(d,p,v,x,y);
	}
}
