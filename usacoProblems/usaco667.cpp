#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out","w", stdout);
    int n;
    cin >> n;
    unordered_map<string, unordered_map<string,int>> m;
    unordered_map<string, unordered_map<string,int> > t;
    for(int i =0;i<n;i++){
        string s, c;
        cin >> s >> c;
        m[s.substr(0,2)][c]++;
        t[c][s.substr(0,2)]++;
    }
    int ans = 0;
    for(auto &p:m){
        unordered_map<string,int> r = t[p.first];
        for(auto& z:r){
            string u = z.first;
            if(u != p.first){ 
                auto it = p.second.find(u);
                if(it != p.second.end()){
                    ans+=(*it).second*z.second;
                }
            }
        }
    }
    cout << ans/2;

}
