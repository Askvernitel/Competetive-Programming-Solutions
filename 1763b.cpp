#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;

    cin >> n >> k;
    int a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];
    map<int, priority_queue<int>> m;
    for(int i =0;i<n;i++) m[a[i]].push(-b[i]);
    
    sort(a, a+n);
    map<int, int> m1;
    int mn = INT_MAX;
    
    for(int i =n-1;i>=0;i--){
        int f = m[a[i]].top();
        mn = min(mn, -f);
        m1[a[i]] = mn;
    }
    int t = k, p =0;
    while(k > 0){
        auto it = m1.upper_bound(t);
        if(it == m1.end()){
            p=1;
            break;
        }
        k-=it->second;
        t+=k;
    }

    if(p) cout << "YES" << '\n';
    else cout << "NO" << '\n';
 
}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
