#include <bits/stdc++.h>
#define int long long
#define maxof(a, b) (((a)>(b))?(a):(b))
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int,set<int>> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
        m[a[i]-i].insert(a[i]); 
    }
    int ans = 0;
    for(auto& [val,s]:m){
        auto t=s.end();
        while(prev(t) != s.begin()){ 
            t--;t--;
            ans += maxof(0, *next(t) + *t);
            if(t==s.begin()) break;
        }
    }

    cout << maxof(0, ans) << '\n';
    
}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
