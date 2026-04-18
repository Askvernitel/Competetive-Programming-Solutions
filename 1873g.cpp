#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> a;
    for(int i = 0;i<n;i++){
        if(s[i] == 'B')
            a.push_back(i);
    }
    int ans = 0;
    if(a.empty()){
        cout << ans << '\n';
        return;
    }
    int pos = 0;
    if(a[0] == 0 || a.back() == n-1){ 
        pos = 1;
    }
    a.insert(a.begin(),-1);
    a.push_back(n);

    int m = a.size();
    vector<int> dist;
    for(int i =0;i<m-1;i++){
        dist.push_back(a[i+1]-a[i]-1);
    }
    int k = dist.size();
    int t = INT_MAX;
    for(int d:dist){ 
        ans+=d;
        t = min(d, t);
    }
 
    if(pos){
       cout << ans << '\n';
        return;
    }

    ans-=t;
    cout << ans << '\n';


}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
