#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<int> v_int;
typedef vector<bool> v_bool;
 
int diag1(int n, int i, int j) {
    return n-j-1 + i;
}
 
int diag2(int n, int i, int j) {
    return i+j;
}
 
void reines1(v_int& reines, v_bool& mc, v_bool& md1, v_bool& md2, int n, int i, int& num) {
    if (i == n) ++num;
    else {
        for (int j = 0; j < n; ++j) {
            if (not mc[j] and not md1[diag1(n,i,j)] and not md2[diag2(n,i,j)]) {
                reines[i] = j;
                mc[j] = true;
                md1[diag1(n,i,j)] = true;
                md2[diag2(n,i,j)] = true;
                reines1(reines,mc,md1,md2,n,i+1,num);
                mc[j] = false;
                md1[diag1(n,i,j)] = false;
                md2[diag2(n,i,j)] = false;
            }
        }
    }
}
 
int main() {
    int n;
    cin >> n;
    v_int reines(n);
    v_bool mc(n,false);
    v_bool md1(2*n-1,false);
    v_bool md2(2*n-1,false);
    int num = 0;
    reines1(reines,mc,md1,md2,n,0,num);
    cout << num << endl;
}


