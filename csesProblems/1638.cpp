#include <bits/stdc++.h>
#define int long long
using namespace std;
int M = 1e9+7;
signed main(){
    int n;
    cin >> n;
    char grid[n+1][n+1];
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    int f[n+1][n+1];
    memset(f, 0, sizeof(f));
    if(grid[0][0] == '*'){
        cout << 0;
        return 0;
    }
    f[0][0] = 1;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(j+1 < n && grid[i][j+1] != '*') f[i][j+1] = (f[i][j+1] + f[i][j])%M;
            if(i+1 < n && grid[i+1][j] != '*') f[i+1][j] = (f[i+1][j] + f[i][j])%M ;
         }
    }
   
    cout << f[n-1][n-1];
}

