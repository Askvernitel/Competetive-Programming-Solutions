#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    if(k <= n){ 
        cout << k << '\n';
        return;
    }

    sort(a, a+n);

    int c = k/n;
    int ans = 0, g = 0;

    for(int i = 0;i<n;i++){
        if(c > a[i]){
            ans += a[i]+1;
            g+=a[i];
        }else{
            ans += c;
            g+=c;
        }
    }   

    if(g < k){
        ans += k-g;
        for(int i =0;i<n;i++){
            if(c == a[i]){
                ans++;
            }
        }
    }
    cout << ans << '\n';

    
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
