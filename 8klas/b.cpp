#include <bits/stdc++.h>
#define int long long
using namespace std;
int const inf = 1e18;
int a[61];
int m = 0;
map<int, int >dp;
int minv = INT_MAX;
int rec(int x, int i, int st){ 
    if(i == m || x < 0) return inf;
    if(dp[x]){ 
        return dp[x];
    }
    if(x == 0){
        return st;
    }

    dp[x] = min(rec(x-a[i], i+1, st+1), rec(x, i+1, st));
    return dp[x];
}

signed main(){
    int n;
    cin >>n;
    int cur = 1;
    while(cur<=inf){
        a[m] = cur;
        if(cur%2){ 
            cur *=2;
        }else{
            cur = cur*2+1;
        }
        m++;
    }
    int ans = 0;
    for(int i = m-1; i>=0;i--){
        if( n== 0) break;
        if(n >=a[i]){
            ans++;
            n-=a[i];
        }
    }
    if(n != 0){
        cout << -1;
    }else{
        cout << ans;
    }




    

    
}
