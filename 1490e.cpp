#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    map<int,vector<int>> m;
    for(int i =0;i<n;i++) m[a[i]].push_back(i);

    sort(a, a+n);
    int maxv = a[n-1];
    int pref[n]; pref[0] = 0;
    for(int i =1;i<n;i++) pref[i] = pref[i-1] + a[i-1];
    set<int> t;
    for(int i = n-1;i>=0;i--){
//        cout << t.end() << " ";
//        cout << (t.lower_bound(a[i] + pref[i]) == t.end()) << " ";
        if(t.size() == 0){t.insert(a[i]); continue;}
        else if(a[i]+pref[i] >= *(t.begin())){t.insert(a[i]);} 
//        cout << *t.begin() << " ";
        //if(t.size() == 1 && (a[i] + pref[i]) > *(t.begin())){t.insert(a[i]); }
    }
    set<int> ans;
    for(auto &x:t){
 //       cout << x << " ";
        for(int ind:m[x]){
            ans.insert(ind+1);
        }
//        cout << a[i] + pref[i] << " ";
    }
    cout << ans.size() << '\n';
    for(auto &x:ans){
        cout << x << " ";
    }
    cout << '\n';
}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
