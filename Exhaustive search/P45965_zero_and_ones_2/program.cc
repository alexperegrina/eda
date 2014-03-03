#include <iostream>
#include <vector>
 
using namespace std;
 
void func(vector<int>& v, int i, int u, int up, int z) {
    int n = v.size();
    if(i == n and up == u) {
        bool first = false;
        for (int j = 0; j < n; ++j) {
            if (first) cout << " ";
            else first = true;
            cout << v[j];
        }
        cout << endl;
        return;
    }
    if (i < n) {
  		if (z < n-u) {
			v[i] = 0;
			func(v,i + 1,u,up,z+1);
		}
		if (up < u) {
			v[i] = 1;
			func(v,i + 1,u,up+1,z);
		}
    }
}
 
int main() {
    int n,u;
    cin >> n >> u;
    vector<int> v(n);
    func(v,0,u,0,0);  
}

