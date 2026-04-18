#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i =0;i<n;i++) cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    int l = 0, r = 0, s = 0, ans =0 ;
    while(r < n){
        if(vec[r] - vec[l] > 1 || s+vec[r] > m){
            ;
             if(r==l){
                l++; r++;
             }else{s-=vec[l];l++;}
             continue;
        }
        else{s+=vec[r]; r++;}
        if(s <= m){
            ans=max(ans,s);
        }
    }
   // cout << s << '\n';
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);

    int tc;

    cin >> tc;

    while(tc--) solve();

}
