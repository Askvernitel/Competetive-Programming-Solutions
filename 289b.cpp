#include <bits/stdc++.h>
#define int long long
using namespace std;
int const N = 10001;
int dp[N], b[N];
signed main(){
    int n, m, d;

    cin >> n >> m >> d;
    int mat[n][m];
    int p = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> mat[i][j];
           // if((mat[i][j]%d)) p=1;
        }
    }
/*    if(p){
       cout << -1;
        return 0;
    }*/
    for(int i =0;i<=N;i++) dp[i] = 0;
   // memset(dp, 0, sizeof(dp));
     memset(b, 0, sizeof(b));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            //dp[mat[i][j]] = 0;
            b[mat[i][j]]++;
            int c = 0;
            for(int k = mat[i][j]; k<=N-d;k+=d){
                dp[k+d] += c + 1;
                b[k+d]++;
                c++;
            }
            c=0;
            for(int k = mat[i][j]; k>=d;k-=d){
                dp[k-d] += c + 1;
                b[k-d]++;
                c++;
            }
//            for(int i =0;i<=N;i++) cout << dp[i] << " ";
       
        }

    }
    int x = m*n;
    int ans = INT_MAX;
    for(int i =0;i<=N;i++){
        //cout << dp[i] << " ";
//        cout << dp[i] << " ";
        if(b[i] == x) ans = min(dp[i], ans);
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;
}
