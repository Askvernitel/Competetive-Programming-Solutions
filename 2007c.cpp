#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int c[n];
    for(int i =0;i<n;i++){
        cin >> c[i];
    }
    
    for(int i =0;i<n;i++){ 
        c[i]%=(a+b);
        int k=c[i]%a;
        int t=c[i]%b;

        if(k < t) c[i] = k;
        else c[i] = t;
    }
    int maxv = 0, minv = LLONG_MAX;
    for(int i =0;i<n;i++){
        maxv = max(maxv, c[i]);
        minv = min(minv, c[i]);
    }
    cout << maxv - minv << '\n'; 

}
signed main(){ 
    int tc;
    cin >> tc;
    while(tc--) solve();
}
