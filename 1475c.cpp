#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b,k;
    cin >> a >> b >> k;

    int a1[k], b1[k];
        
    for(int i = 0; i < k;i++) cin >> a1[i];
    for(int i = 0; i < k;i++) cin >> b1[i];
    
    map<int, int> bs; map<int, int> gs;
    for(int i =0;i<k;i++){
        bs[a1[i]]++;
        gs[b1[i]]++;
    }
    int t =0;

    for(auto &x:bs){ 
        t += ((x.second)*(x.second-1))/2;
    }
    for(auto &x:gs){
        t+=((x.second)*(x.second-1))/2;
    }
    int combs = (k*(k-1))/2;

    cout << combs - t << '\n';
    



}


signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();


}
