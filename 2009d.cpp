#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> f, s;
    for(int i =0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(y == 0) f.insert(x);
        else s.insert(x);
    }

    int ans = 0;
    for(int x:f){
        if(s.find(x) != s.end()){
            ans += s.size()-1;
            ans += f.size()-1;
        }
        if(s.find(x+1) != s.end() && f.find(x+2) != f.end()) ans++;
        if(s.find(x-1) != s.end() && s.find(x+1) != s.end()) ans++;
    }
    cout << ans << '\n';
}

signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}
