#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mxo = 0;
    int mxe = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i]%2) mxo = max(a[i], mxo);
        if(!(a[i]%2)) mxe = max(a[i], mxe); 

    }
    sort(a.begin(), a.end());
    int p = 1;
    for(int i =0;i<n-1;i++){
        if(a[i]%2 != a[i+1]%2){p=0;break;}
    }
    if(p){cout << 0 << '\n'; return;}
    int ans = 0;
//    int ecnt = 0;
  //  int k = n;
    for(int i=0;i<n;i++){
        if(a[i] > mxo && !(a[i]%2)){
            mxo = max(mxo, a[i]+mxe);
            ans++;
        }

        if(a[i] < mxo && !(a[i]%2)){
            mxo = max(mxo,a[i]+mxo);
            ans++;
        }
    }
    cout << ans << '\n';
    //if(k == -1){cout << ans; return;}

}

signed main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) solve();
}
