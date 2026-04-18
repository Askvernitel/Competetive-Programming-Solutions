#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxv = 0;
int dfs(int cur, vector<int>& pts, vector<int>& b, set<int>& nvis, int sum){
    if(nvis.find(cur) == nvis.end() || nvis.lower_bound(cur) == nvis.end()){
        return sum;
    }
    nvis.erase(cur);
    if(nvis.lower_bound(cur) == nvis.begin() || nvis.lower_bound(cur) == nvis.end()){
        sum = max(sum+pts[cur], dfs(b[cur], pts,b,nvis, sum));
    }else{
//        cout << "cur: " << cur << " "<< pts[cur] << " \n";
        sum = max(dfs(*prev(nvis.lower_bound(cur)), pts, b, nvis, sum+pts[cur]), dfs(b[cur], pts,b,nvis, sum));
    }

    return sum;
}

void solve(){
    int n;
    cin >> n;
    vector<int> pts(n+5), b(n+5);
    set<int> nvis;
    for(int i =0;i<n;i++)
        cin >> pts[i];
    for(int i =0;i<n;i++) nvis.insert(i); 

    for(int i =0;i<n;i++){cin >> b[i]; b[i]--;}


    cout <<  dfs(0, pts, b, nvis, 0) << '\n';
}


signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
