#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int a[2001][2001];
int dp[2001][2001];
void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin >> ch;
            if(ch == 'X') a[i][j]=1;
            else a[i][j] =0;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0;i<m;i++){
        if(a[n-1][i]) dp[n-1][i] = 1;
        else dp[n-1][i]=0;
    }

    int temp[m];
    int temp1[m+1];
    for(int i=n-1;i>=0;i--){
        if(i != n-1){
            for(int j=1;j<=m;j++){
                dp[i][j] = (dp[i][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
        int p[m+1];
        memset(p, 0, sizeof(p));
        for(int j= 0;j<m;j++){
            temp[j] = dp[i][j];
        }
        for(int j= 0;j<=m;j++){
            temp1[j] = 0;
        }
        for(int j=0;j<m;j++){
            if(!a[i][j]) continue;
            int idx1 = max((int)0, j-d);
            int idx2 = min((int)m, j+d+1);
            temp1[idx1] = temp1[idx1]+temp[j];
            temp1[idx2] = temp1[idx2]-temp[j];
            /*
            for(int v=j+1;v<=min(m-1,j+d);v++){
                if(a[i][v]){
                    dp[i][v]=(dp[i][v]+temp[j]%mod)%mod;
                    dp[i][j]=(dp[i][j]+temp[v]%mod)%mod;
            }*/
        } 
        for(int j=1;j<=m;j++){
            temp1[j] = (temp1[j-1]+temp1[j]);
        }
 
        for(int j=0;j<m;j++){
            dp[i][j] = (temp1[j])%mod;
        }/*
        for(int j=0;j<m;j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';*/
        if(i == 0) continue;
        for(int j=0;j<m;j++){
            if(!a[i][j]) continue;
            int idx1 = max((int)0,j-d+1);
            int idx2 = min(m,j+d);
            dp[i-1][idx1]=(dp[i-1][idx1] + dp[i][j]);
            dp[i-1][idx2]=dp[i-1][idx2]-dp[i][j];//(mod + dp[i-1][min(m-1,j+d)]%mod - dp[i][j]%mod)%mod;
            /*
            for(int v=max((int)0,j-d+1);v<=min(m-1,j+d-1);v++){
                if(a[i-1][v]){
                    dp[i-1][v] =(dp[i-1][v] + dp[i][j]%mod)%mod;
                }
            }*/
        }
    }
    int ans = 0;
    for(int j =0;j<m;j++){
        if(!a[0][j]) continue;
        ans = (ans+dp[0][j]%mod)%mod;
    }
    cout << (mod+ans%mod)%mod << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) solve();
}
