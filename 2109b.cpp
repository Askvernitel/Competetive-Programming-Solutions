#include <bits/stdc++.h>
#define int long long
using namespace std;
int n ,m,a,b;
int lg(int x){ 
    int res = 0;
    while(x>1){
        x=(x+1)/2;
        res++;
    }
    return res;
}
int lg1(int x, int r, int c){
    int res=0;
    while(x > 1){
//        cout << x << '\n';
        res++;
        int t = max({(r-a)*c,r*(b-1),(c-b)*r, (a-1)*c});
        vector<pair<int,int>> v;
        //pair<int,int> d;
        if(t == (r-a)*c){ 
            v.push_back({r-a,0});
        }if(t == r*(b-1)){
            v.push_back({0,b-1});
        }if(t==(c-b)*r){ 
            v.push_back({0,c-b});
        }if(t==(a-1)*c){
            v.push_back({a-1,0});
        }
        pair<int,int> d={0,0};
        for(pair<int,int> z:v){ 
            if(d.first == 0){ 
                if(z.first > d.second || z.second > d.second){ 
                    d =z;
                }
            } else if(d.second == 0){
                if(z.first > d.first || z.second > d.first){ 
                    d =z;
                }
            }
        }
        r-=d.first;
        c-=d.second;
        a=(r+1)/2;
        b=(c+1)/2;
        
        x=r*c;
    }
    return res;
}
void solve(){
    cin >> n >> m >> a >> b;
    
    int k1 = n-a;
    int k2 = a-1;
    int k3 = m-b;
    int k4 = b-1;

    int t1 =lg(n-k1)+1+lg(m);
    int t2 =lg(n-k2)+1+lg(m);
    int t3 =lg(m-k3)+1+lg(n);
    int t4 =lg(m-k4)+1+lg(n);
    cout << min({lg1(n*m,n,m), t1,t2,t3,t4}) << '\n';

}
signed main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}
