#include <bits/stdc++.h>

using namespace std;
int M=1e9+7;
int main(){
    int n, m;
    cin >>n >>m;
    int c[n];
    for(int i = 0;i<n;i++) cin >> c[i];

    int f[m+1];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i =0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(j+c[i] <=m && f[j] != 0) f[j+c[i]] = (f[j] + f[j+c[i]])%M;
        }
    }
    cout << f[m];


}
