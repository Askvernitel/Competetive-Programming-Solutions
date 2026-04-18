#include <bits/stdc++.h>

using namespace std;

int main(){
    int inf = -1e9;
    int n, m;
    cin >> n >> m;
    int a[n];
    
    for(int i =0;i<n;i++) cin >> a[i];

    int f[n+1][m+2];
    for(int i =0;i<n+1;i++){
        for(int j = 0;j<m+2;j++){
            f[i][j] = 0;
        }
    }
    
    for(int i =0;i<=m;i++){
        f[0][i] = 1;
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<=m;j++){
            if(a[i] == 0){

                if(j-1 >= 0) f[i+1][j-1] += f[i][j];
                f[i+1][j+1] += f[i][j];
                f[i+1][j] += f[i][j];
            }else{
                f[i+1][a[i]+1] = f[i][a[i]];
                f[i+1][a[i]-1] = f[i][a[i]];
                f[i+1][a[i]] = f[i][a[i]];
                break;
            }
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j =0;j<=m;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for(int i =0;i<=m;i++){
        ans = max(ans, f[n][i]);
    }

    cout << ans << '\n';
}
