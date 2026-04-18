#include <bits/stdc++.h>
#define int long long
using namespace std;

int M = 1e9 + 7;
int pow_mod(int val, int exp){

    int cur = 1;

    int x = val;
    int ans = 1;
    int it = 0;
    while(exp > 0){ 

        if(exp & 1){
            ans = (ans*x)%M;
        }
        x=(x*(x%M))%M;
        exp >>= 1;
    }

    return ans;
}
void solve(){
    int n,k;
    cin >> n >> k;

    cout << pow_mod(n,k) << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
