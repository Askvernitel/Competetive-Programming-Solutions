#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int xorr = 0;
    map<int,int> m;
    for(int i =0;i<n;i++) m[a[i]]++;
    for(auto &x:m) xorr = (xorr ^ x.first);
    int pos = 0;
    for(auto &x:m){
        int txor = xorr ^ x.first;
        if(x.second > 1 && (txor ^ x.first) == x.first){pos =1; break;}
        if(x.second > 1 && xorr == x.first){pos=1;break;}
        if(txor == x.first){pos = 1; break;}

    }
    if(pos) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main(){
//    ios_base::sync_with_stdio(false);
  //  cin.tie(0);
    int tc;
    cin >> tc;

    while(tc--) solve();

}
