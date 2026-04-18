#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;

    cin >> n;

    char g[n][n];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }

    int ans[n];
    memset(ans, 0 ,sizeof(ans));
    int c[n];
    memset(c, 0 ,sizeof(c));
    for(int i=n-1;i>=0;i--){
        int cnt = 0;
        for(int j=0;j<i+1;j++){
            int cur = j+1;
            if(g[i][j]=='1'){
                cnt++;
            }
        }
        int zz = 0;
        int idx= 0;
        for(int j=0;j<=n;j++){
            if(ans[j] != 0){
                continue;
            }
            if(zz == cnt){ 
                idx=j;
                break;
            }

            if(ans[j] == 0){ 
                zz++;
            }
        }
        ans[idx] = i+1;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
int main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}
