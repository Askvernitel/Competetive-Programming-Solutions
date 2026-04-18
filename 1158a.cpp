#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    int b[n], g[m];
    for(int i =0;i<n;i++) cin >> b[i];
    for(int i =0;i<m;i++) cin >> g[i];

    sort(b, b+n, greater<int>());
    sort(g, g+m, greater<int>());

    if(b[0] > g[m-1]){cout << -1; return 0;}
    int ans = 0, nf =1;
    for(int i =0;i<m;i++){
        if(g[i] == b[0]) nf = 0;
        ans += g[i];
    }
    int s = 1;
    if(nf){
        ans += b[0];
        ans += (b[1]*(m-1));
        s++;
    }
    for(int i =s;i<n;i++){
        ans += (b[i]*(m));
    }

    cout << ans;

}
