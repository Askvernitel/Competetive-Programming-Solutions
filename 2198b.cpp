#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, c;


int f(int d){

    return d*a - (d/b)*c;
}
void solve(){
    int n, x;
    cin >> n >> x;


    cin >> a >> b >> c;
    int l=-1, r = INT_MAX;
    while(r -l > 1){ 
        int m = (r+l)/2;
        if(f(m) >= x){ 
            r = m;
        }else{
            l = m;
        }
    }
    cout << r/b << '\n';
}
signed main(){ 
    int tc;
    cin >> tc;
    while(tc--) solve();
}
