#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
bool ff(int x, pair<int,int> p[], int i, int y){ 
    return (((x-(p[i].F+p[i].S))*(x-(p[i].F+p[i].S))) <= ((p[i].S*p[i].S)-(y*y)));
}
bool f(int x, pair<int,int> p[], int i, int y){ 
    return (y*y<=((p[i].S*p[i].S)-(x*x)));
}
//2*x*xj-2*x*xi+xi**2 - xj**2;
bool g(int x, int xi, int xj){
    cout << ((2*x*xj)-(2*x*xi)+(xi*xi)-(xj*xj)) << "\n";
    return ((2*x*xj)-(2*x*xi)+(xi*xi)-(xj*xj)) >= 0;
}
int rb(pair<int,int> p){ 
    return p.F+2*p.S;
}
void solve(){
    int n,m;
    cin >> n >> m;
    int x[n], r[m]; for(int i =0;i<n;i++){
        cin >> x[i];
    }
    for(int i =0;i<n;i++){
        cin >> r[i];
    }
    pair<int,int> p[n];
    for(int i =0;i<n;i++){
        p[i] = {x[i]-r[i], r[i]};
    }
    sort(p,p+n);
    int ans = 0;
    int i= 0;
    map<int,int> am;
    while(i < n){
        //int res = 0;
        for(int y=p[i].F;y<=(p[i].F+(2*p[i].S));y++){
            int l = -1, r=p[i].S+1;
            while(r-l>1){
                int mid = (l+r)/2;
                if(ff(y,p,i,mid)){ 
                    l=mid;
                }else{
                    r=mid;
                }
            }
            am[y]=max(am[y],2*l+1);
            //res+=(l+1);
        }
        /*
        int o = p[i].S;
        int t = (res-2*o-1)*4;
        res = t;
        res+=4*o+1;
        int r = rb(p[i]);
        int j = i+1;*/
        i++;
    }
    for(auto &[c,d]:am){
        ans+=d;
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
