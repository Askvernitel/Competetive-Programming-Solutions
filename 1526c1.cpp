#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int inf = 1e17 + 7;
    int n;
    cin >> n;

    int a[n];

    for(int i =0;i<n;i++) cin >> a[i];

    int f[n+1][n+1];
    for(int i =0;i<n+1;i++){
        for(int j =0;j<n+1;j++){
            f[i][j] = -inf;
        }
    }
    f[0][0] = 0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            f[i+1][j] = max(f[i][j], f[i+1][j]);
            if(f[i][j] + a[i] >= 0){
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j] + a[i]);
            }
        }
    }

    int ans = 0;
    /*for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            cout << f[i][j] << " "; 
        }
        cout << endl;
    }*/
   
    for(int i =n;i >=0;i--){
        if(f[n][i] != -inf){ans = i; break;}
     
    }
    cout << ans;
}
