#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 10;
bool sev(int n ){ 
    while(n!=0){
        if(n%10 == 7) return true;
        n/=10;
    }
    return false;
}
map<int,int> dp;
int rec(int x, int c1, int c2, int cnt){ 
    if(cnt >= 10){ 
        return INT_MAX;
    }
    if(dp.find(x) != dp.end()) return dp[x];
    if(sev(x)){ 
        return cnt;
    }
    dp[x] = min(rec(x+c1, c1, c2, cnt+1), rec(x+c2, c1,c2, cnt+1));
    return dp[x];
}
void solve(){
    int n;
    cin >> n;
    int k = 0;
    int c1 = 0, c2 =0;
    int j =1;
    int ans = INT_MAX;
    while(n != 0){
        c1+=9*j;
        k+=n%10*j;
        ans = min(rec(k, c1, c2,0), ans);
        c2=c1;
        j*=10;
        n/=10;
    }
    dp={};
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
