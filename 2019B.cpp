#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int f[n];
    memset(f, 0,sizeof(f));
    f[0] = n-1;
    for(int i =1;i<n;i++){
        f[i] += i*(n-i) + n-i-1;
    }
    map<int,int> m;
    for(int i =0;i<n;i++){
        m[f[i]]++;
        if(i - 1 >= 0){
            m[f[i]-(n-i-1)] += a[i]-a[i-1]-1;
        }
    }
    
    while(q--){
        int k;
        cin >> k;
        
        cout << m[k] << " ";
    }
    cout << '\n';
}



signed main(){

    int tc;
    cin >> tc;

    while(tc--) solve();


}
