#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){ 
    if(b == 0) return a;
    return gcd(b, a%b);
}
int N = 5001;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int dp[N];
    for(int i = 0;i<N;i++) dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j =0;j<N;j++){
            if(dp[j] == INT_MAX) continue;
            dp[gcd(j,a[i])]=min(dp[j]+1,dp[gcd(j,a[i])]);
        }
    }
    int ans = INT_MAX;
    int gc = 0;
    for(int i =1;i<N;i++){
        if(dp[i] != INT_MAX){ans=dp[i]-1; gc=i;break;}
    }
    int f = 0; 
    for(int i =0;i<n;i++){
        if(a[i] == gc) f=1;
        if(a[i] != gc) ans++;
    }
    cout << ans-((f)?0:1) << '\n';

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
