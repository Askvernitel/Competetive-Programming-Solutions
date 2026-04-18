#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
    int n;
    cin >> n;

    int k = n*n - (n-1)*(n-1);
    int ans = 0;
    for(int i = 3;i*i <= k;i+=2){
        ans++;
    }
    cout << ans << '\n';
}


signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
