#include <bits/stdc++.h>

using namespace std;
int n1, n2, k1, k2;
int dp[101][101], f[101][101];
int const M = 1e8;
int solve(int k, int cnt1, int cnt2, int c1, int c2){
    if(c1 > n1 || c2 > n2) return 0;
    if(k < 0) return 0;
    if(k == 0) return 1;
    //if(dp[cnt1`][cnt2][c1][c2][k]) return dp[cnt1][cnt2][c1][c2][k];
    
    int ans = 0;

    if(cnt1 < k1 ){
        if(!dp[c1][c2]) dp[c1][c2] = solve(k - 1, cnt1+1, 0, c1 + 1, c2)%M;
        ans += dp[c1][c2]%M;
    }
    if(cnt2 < k2){
        if(!f[c1][c2]) f[c1][c2] = solve(k - 1, 0, cnt2+1, c1, c2+1) %M ;
        ans += f[c1][c2]%M;
    }
    //dp[cnt1][cnt2][c1][c2][k] = ans;
    return ans;
    
}

int main(){

    cin >> n1 >> n2 >> k1 >> k2;

    int m = n1 + n2;
    cout << solve(m, 0, 0, 0,0);


}
