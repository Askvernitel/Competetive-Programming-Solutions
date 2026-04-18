#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;

int cost[200001];

void solve(){
    int n;
    cin >>n ;
    memset(cost,0,n*4);
    for(int i=1;i<=n;i++){
        cin >> cost[i];
    }
    vector<int> children[n+1];
    for(int i =0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u);
    }
    int pars[n+1];
    int mpar[n+1];
    int xpar[n+1];
    int ans[n+1];
    mpar[0]=0;
    xpar[0]=INT_MIN;
    pars[0]=0;
    queue<pair<int,int>> q;
    q.push({1,0});
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    int level = 0;
    while(!q.empty()){
        int sz = q.size();
        vector<pair<int,int>> cur;
        for(int i =0;i<sz;i++){
            cur.push_back(q.front());
            q.pop();
        }
        for(int i =0;i<sz;i++){
            pair<int,int> x = cur[i];
            int t;
            if(level%2){ 
                t= pars[x.S]-cost[x.F];
            }else{
                t= cost[x.F]+pars[x.S];
            }
            mpar[x.F]=min(mpar[x.S], t);
            xpar[x.F]=max(xpar[x.S], t);
            pars[x.F]=t;
        
            ans[x.F]=max((level%2)?cost[x.F]-pars[x.S]+xpar[x.S]
                          :cost[x.F]+pars[x.S]-mpar[x.S], cost[x.F]);
            vis[x.F]=1;
            for(int i =0;i<children[x.F].size();i++){
                if(vis[children[x.F][i]]) continue;
                q.push({children[x.F][i], x.F});
            }
        }
        level++;
        
    }
    for(int i =1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
