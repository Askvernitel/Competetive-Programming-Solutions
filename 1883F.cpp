#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;

    cin >> n;


    int a[n];

    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    set<int> s1;
    map<int,int> s2;
    for(int i =0;i<n;i++){
        s2[a[i]]++;
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        if(s1.find(a[i])==s1.end()){
            s1.insert(a[i]);
            ans+=s2.size();
        }
        s2[a[i]]--; 
        if(s2[a[i]] == 0) s2.erase(a[i]);
    }
    cout << ans <<'\n';
}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
    
