#include <bits/stdc++.h>
#define int long long 
using namespace std;

int res = 0;
void rec(int t, int c){
    if(t == 0){res++; return;}
    if(t < 0 || c > 2) return;

    for(int i =0;i<=9;i++){
        rec(t-i, c+1);
    }
}

int arr[10];
void calc(){
    arr[0] = 1;
    for(int i =1;i<10;i++){
        rec(i, 0);
        arr[i] = res;
        res = 0;
    }
}

void solve(){
    int n;
    cin >> n;
    int ans = 1;
    while(n!=0){
        int b = n%10;
        ans *= arr[b];
        n/=10;
    }

    cout << ans << '\n';

}

signed main(){
    int tc;
    cin >> tc;
    calc();
    while(tc--) solve();
}   
