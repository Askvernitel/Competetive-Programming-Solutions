#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;

    int p = (n*(n+1))/2;
    if(p < m || m < n){ 
        cout << -1 << endl;
        return;
    }
    int cof[n+2];
    memset(cof,0,sizeof(cof));
    set<int> nu;
    for(int i =1;i<=n;i++){
        nu.insert(i);
    }
    int l = 1;
    cof[1] = n;
    int sum = n;
    while(sum != m){
        if(cof[l] != 1 && sum+((cof[l]-1)) < m){ 
            sum+=((cof[l]-1));
            cof[l+1]+=cof[l]-1;
            cof[l]=1;
            l++;
        }else if(cof[l] != 1){
            cof[l+1]++;
            cof[l]--;
            sum++;
        }
        else{
            l++;
        }
    } 
    if(sum != m){ 
        cout << -1 << '\n';
        return;
    }
    int root = 1;
    int cur = 2;
    while(cof[cur] != 0){
        root++;
        cur++;
    }
    set<pair<int,int>> used;
    for(int i =1;i<=l+1;i++){
        if(cof[i] > 0 && i!=1 && (used.find({i,i-1}) == used.end() && used.find({i-1,i}) == used.end())){
            used.insert({i,i-1});
            cof[i]--;
        }

 
        for(int j =0;j<cof[i];j++){
            auto it=nu.upper_bound(i);
            if(used.find({i,*it}) == used.end() && used.find({*it,i}) == used.end() && it != nu.end())used.insert({i,*it});
            if(it == nu.end()) continue;
            nu.erase(it);
        }
    }
    
    cout << root << '\n';
    for(auto &[c,d]:used){
        cout << c << " "  << d << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) solve();
}
