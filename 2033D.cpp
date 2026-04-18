#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int pref[n+1];
    pref[0]=0;

    for(int i =1;i<n+1;i++) pref[i] = pref[i-1] + a[i-1];
    map<int, int> m;
    for(int i =0; i < n;i++){
        m[pref[i]]++;
    }
    int ans = 0;
    set<int> s;
    for(int i = 1;i<n+1;i++){
        if(a[i-1] == 0 || pref[i] == 0){
            ans++;
            cout << pref[i] << " ";
            s={};
            continue;
        }
        if(s.find(pref[i])!=s.end()){
            ans++;
            s = {};
        }else{
            s.insert(pref[i]);
        }
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
