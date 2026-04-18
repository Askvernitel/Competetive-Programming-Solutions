#include <bits/stdc++.h>

using namespace std;
int M = 1e9+7;
int main(){
    int n, m;

    cin >> n >> m;  
    int c[n];
    for(int i =0;i<n;i++) cin >> c[i];
    int f[m+1];
    for(int i =0;i<m+1;i++){
        f[i] = 0;
    }
    f[0]=1;
   
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(c[j] + i <= m){
                f[c[j] + i] = (f[c[j]+i] + f[i])%M;
            }
        }
    }
    cout << f[m];
}
