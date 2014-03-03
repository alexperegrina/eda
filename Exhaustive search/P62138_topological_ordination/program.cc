#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<vector<int> > Matriu;
 
void escriu(vector<int>& vs, int n){
    for(int i = 0; i < n; ++i){
        if (i == 0) cout << vs[i];
        else cout << " " << vs[i];
    }
    cout << endl;
}
 
void ordtopo (const Matriu& M, vector<int>&vs, vector<int>& pred, int n, int i) {
    if (i == n) escriu(vs,n);
    else {
        for (int j = 0; j < n; ++j) {
            if (pred[j] == 0) {
                vs[i] = j;
                --pred[j]; // pondrá pred[j] = -1 => así no lo volverán a coger
                for(int k = 0; k < M[j].size(); ++k) --pred[M[j][k]];
                ordtopo(M,vs,pred,n,i+1);
                ++pred[j]; // pondrá pred[j] = 0;
                for(int k = 0; k < M[j].size(); ++k) ++pred[M[j][k]];
            }
        }
    }
}
 
int main(){
    int n, p;
    cin >> n >> p;
    Matriu M(n);
    vector<int> pred(n,0);
    for (int i = 0; i < p; ++i){
        int a, b;
        cin >> a >> b;
        M[a].push_back(b);
        ++pred[b];
    }
    vector<int> vs(n);
    ordtopo(M,vs,pred,n,0);
}
