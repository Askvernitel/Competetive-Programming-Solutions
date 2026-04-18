#include <bits/stdc++.h>
#define int long long 
using namespace std;

int path[200005], maxv = 0;
void dfs(int cur, int par, map<int,vector<int>>& mexs){
//    if(mexs[cur].size() == 0 || cur < 0) return;
    for(int next:mexs[cur]){
//        cout << next << '\n';
        //cout << 1 << '\n'; 
//        if(next < 0 || next > mexs[cur].size() || cur < 0) continue;
        if(next != cur && !path[next]){
            maxv = max(maxv, next);
            path[cur] = 1;
            dfs(next, cur, mexs);
            path[cur] = 0;
        }

    }

}
void solve(){
    int n, m;
    cin >> n >> m; 
    maxv = 0;
    map<int, vector<int>> mexs = {{0,{}}};
//    mexs.clear();
//    memset(path, 0, sizeof(path));
    for(int i =0;i<n;i++){
        int l;
        cin >> l;
        int a[l];
        int mex = 0;
        for(int j=0;j<l;j++) cin >> a[j];
        sort(a, a+n);

        for(int j =0;j<l;j++){
            if(a[j] == mex) mex++;
        }
        int next_mex = mex + 1;
        for(int j =0;j<l;j++){
            if(a[j] == next_mex) next_mex++;
        }
//        cout << mex << '\n';
        mexs[mex].push_back(next_mex);
        if(mex != 0) mexs[0].push_back(mex);
    }
    dfs(0, -1, mexs);
    int ans = 0;

   /* for(int i =0;i<4;i++){
        for(int j =0;j<mexs[i].size();j++){
  //          cout << mexs[i][j] << " " << i << '\n';
        }
    }*/
    //cout << maxv << '\n';
    if(m > maxv) ans += maxv*(maxv+1);
    if(m > maxv) ans += (((maxv+1) + m)*(m-maxv))/2;
    if(m <= maxv) ans += maxv*(m+1);
    cout << ans << '\n';
}


signed main(){
//    ios_base::sync_with_stdio(false);
  //  cin.tie(0);
    int tc;

    cin >> tc;

    while(tc--) solve();

}
