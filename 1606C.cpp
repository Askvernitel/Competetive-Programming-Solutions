#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int ans = 0;
    int cnt = 0, t =0;
    while(k>=0 && t<n-1){
        k-=pow(10, a[t+1])/pow(10,a[t])-1;
        ans+=pow(10,a[t])*(pow(10,a[t+1])/pow(10,a[t])-1);
        if(k >= 0)
        t++;
    }
 //   cout << ans << '\n';
   // cout << k << '\n';
//    cout << k << '\n';
    //if(k < 0){cout << ans + (pow(10,a[t])*(k+1)) << '\n'; return;}
    int d = pow(10,a[t]);
//    cout << ((k+1) * d) << '\n';
    ans += ((k+1) * d);

    cout << ans << '\n';
}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
