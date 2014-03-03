#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct arc {
	int x;
	int v;
	int dis;
};
typedef pair<int, int> ArcP;//first = node->v, second=dis
typedef vector< vector<ArcP> > GrafP;
// arc amb pes
// graf amb pesos
void dijkstra(const GrafP& G, int s, vector<int>& d, vector<int>& p) {
	int n = G.size();
	d = vector<int>(n, 9999999); d[s] = 0;
	p = vector<int>(n, -1);
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
				if (d[v] > d[u] + c) {
					d[v] = d[u] + c;
					p[v] = u;
					Q.push(ArcP(d[v], v));
				}
			}
		}
	}
}

int main() {
	int n,m,u,x,y;
	while(cin >> n >> m) {
		vector<int> d; //distancia
		vector<int> p; //predecesor
		GrafP G(n);
		ArcP arc;
		for(int i = 0; i < m; ++i) {
			cin >> u >> arc.second >> arc.first;
			G[u].push_back(arc);
		}
		cin >> x >> y;
		dijkstra(G,x,d,p);
		if(p[y] != -1) cout << d[y] << endl;
		else if(y == x) cout << 0 << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}
