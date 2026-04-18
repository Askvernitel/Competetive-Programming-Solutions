#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;

    cin >> k >> n;
    int a[k], g[n];
    unordered_map<int,unordered_set<int>> m;
    
    for(int i =0;i<k;i++){
        cin >> a[i];
    }
    for(int i =0;i<n;i++){
        int t;
        cin >> t;
        g[i] = t;
    }
    unordered_set<int> s;
    int pref[k+1];
    pref[0] = 0;
    for(int i =1;i<k+1;i++){ 
        pref[i] = pref[i-1] + a[i-1];
    }
    int ans =0;
    for(int i =1;i<k+1;i++){
        for(int j=0;j<n;j++){
            m[g[j]-pref[i]].insert(g[j]);
            if(m[g[j]-pref[i]].size() == n) s.insert(g[j]-pref[i]);
        }
    }
/*    
    for(auto& x:m){ 
        if(x.second.size() == n){
            ans++;
        }
    }*/
    cout << s.size() << '\n';
    
}
