#include <bits/stdc++.h>
#define int long long
using namespace std;
int const M = 1e9+7;
int n, k,d;
int dp[105][105];
int f(int t, int p){ 
    if(t < 0) return 0;
    if(t == 0) return 1;
    if(dp[t][p]) return dp[t][p];

    for(int i =1;i<=p;i++){
        dp[t][p] = (dp[t][p]%M + f(t-i, p)%M)%M;
    }
    return dp[t][p];
}
signed main(){
    memset(dp, 0, sizeof(dp));

    cin >> n>> k >> d;

    cout << (M+f(n, k)-f(n, d-1))%M << '\n';
}
