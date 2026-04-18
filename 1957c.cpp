#include <bits/stdc++.h>

using namespace std;
int fs[300001];
int mod = 1e9 + 7;
int f(int x){
    if(x <= 0) return 1;
    if(!fs[x]) fs[x] = ((x*(x-1)/2)*(f(x-2)%mod)+ f(x-1)%mod)%mod;
    return fs[x];
}
void solve(){
    int n, k;
    cin >> n >> k;

    for(int i =0;i<k;i++){
        int a, b;
        cin >> a >> b;
        if(a != b) n-=2;
        else n--;
    }

    cout << f(n);


}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
