#include <bits/stdc++.h>
#define int long long 
using namespace std;
int const inf = 1e18 + 10;
void solve(){
    int n, m;
    cin >> n >> m;

    if(!(n%m)){cout << 0 << '\n'; return;}

    if(m%2){cout << -1 << '\n'; return;}


    int k = n%m;
    int ans = 0;
    int p = k;
    int t = k;
    while(p < inf && p%m !=0){ 
        ans += t;
        p *= 2;
        t*=2;
        t%=m;
    }
    if(p%m != 0){cout << -1 << '\n'; return;}
    cout << ans << '\n';


}
signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
