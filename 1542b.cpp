#include <bits/stdc++.h>

using namespace std;
#define int long long
void solve(){
    int n, a, b;
    cin >> n>> a >> b;
    string ans = "No";
    int z=1;
    while(z<=n){ 
        int k = n-z;
        
        if(!(k%b)){
            ans = "Yes";
            break;
        }
        z*=a;
        if(z==1) break;
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
