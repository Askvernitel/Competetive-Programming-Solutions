#include <bits/stdc++.h>
#define int long long

using namespace std;


int n, k;
map<pair<int,int>,int> m, am;
unordered_map<int,pair<int,int>> tt, mm;
int f(int cur, int prev, vector<vector<int>>& s){ 
    vector<pair<pair<int,int>,int>> cnts;
    int res = 1;
    vector<int> t = s[cur];
    for(auto p:t){
        if(p== prev) {
            continue;
        }
        int c = f(p, cur, s);
        cnts.push_back({{p, cur}, c});
        res += c;
    }
    
    for(auto& v:cnts){ 
        v.second = n-v.second; 
        am[v.first] = v.second;
        am[{v.first.second, v.first.first}] = n-v.second;
    }
    return res;
}
int calc(int cur, int prev, int k, vector<vector<int>>& s){ 
    vector<pair<pair<int,int>,int>> cnts;
    int res = 1; 
    vector<int> t = s[cur];
    if(mm.find(cur) != mm.end() && mm[cur].second != 0){
        res=mm[cur].second;
        if(mm[cur].first == -1){ 
            return res;
        }
        res += calc(mm[cur].first, cur, k, s);
        return res;
    }
    for(auto p:t){ 
        if(p==prev){ 
            continue;
        }
        int c = 0;
        if(m[{cur,p}]){ 
            c = m[{cur,p}];
            res += c;
            continue;
        }
        if(am[{cur,p}] >= k){
            c = calc(p, cur, k, s);
        }
        m[{cur, p}] = c;
        res+=c;
    }
    mm[cur] ={prev, res};

    return res;
}

void solve(){

    cin >> n >> k;

    vector<vector<int>> s(n+1);
    for(int i =0;i<n-1;i++){
        int v, w;
        cin >> v >> w;
        s[v].push_back(w);
        s[w].push_back(v);
    }
    f(1,0,s);
    int ans =0;
    for(int i =1;i<=n;i++){
        ans += calc(i,-1,k,s);
    }
    cout << ans << '\n';
    m={};
    mm={};
}
signed main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) solve();
}
