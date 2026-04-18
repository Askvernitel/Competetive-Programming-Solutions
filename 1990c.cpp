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
    int maxv=0;
    int sum =0;
    set<int> s;
    int b[n];
    for(int i=0;i<n;i++){
        if(s.find(a[i]) != s.end()) maxv = max(a[i], maxv);
        else s.insert(a[i]);
        sum+=a[i];
        b[i] =maxv;
    }
    map<int, int> m;
    for(int i = 0;i<n;i++){ 
        m[b[i]]++;
    }

    while(m[0] != n){
        auto it = m.end();
        int p = 0;
        set<int> t;
        while(it != m.begin()){ 
            it--;
            if(it->first == 0){ 
                it->second += p;
                break;
            }
           sum += it->first*it->second;
            it->second--;
            if(it->second != 0){ 
                it->second += p;
                p = 0;
            }else{
                t.insert(it->first);
            }
            p++;
        }
        for(auto &x:t) m.erase(x);
    }
    cout << sum << "\n";

}

signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
