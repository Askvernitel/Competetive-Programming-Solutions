#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
int n;
int f(set<pair<int,int>>& sx, set<pair<int,int>>& sy, pair<int,int> del, int type){
    if(!type){ 
        sx.erase({del.S, del.F});
    }
    int minx=sx.begin()->F;
    int maxx=sx.rbegin()->F;
    if(type){
        sy.erase({del.S, del.F});
    }
    int miny=sy.begin()->F;
    int maxy=sy.rbegin()->F;
    int sz;
    if(type){ 
        sy.insert({del.S, del.F});
    }else{
        sx.insert({del.S, del.F});
    }
    int res= (maxx-minx+1)*(maxy-miny+1);
    if(n-1>=res){
        return res+min(maxx-minx+1, maxy-miny+1);
    }
    return res;
}
void solve(){
    cin >> n;
    set<pair<int,int>> sx, sy;
    for(int i =0;i<n;i++){
        int x, y;
        cin >> x >> y;
        sx.insert({x,y});
        sy.insert({y,x});
    }
    if(n == 1){ 
        cout << 1 << '\n';
        return;
    }
    pair<int,int> v = *sx.begin();
    int ans = LLONG_MAX;

    sx.erase(v);
    ans = min(f(sx,sy,v,1), ans);
    sx.insert(v);

    v=*sx.rbegin();
    sx.erase(v);
    ans = min(f(sx,sy,v,1), ans);
    sx.insert(v);

    v=*sy.begin();
    sy.erase(v);
    ans = min(f(sx,sy,v,0), ans);
    sy.insert(v);

    v=*sy.rbegin();
    sy.erase(v);
    ans = min(f(sx,sy,v,0), ans);
    sy.insert(v);
    
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
