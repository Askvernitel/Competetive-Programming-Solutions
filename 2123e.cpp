#include <bits/stdc++.h>


using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int p[n+1];
    memset(p,0,sizeof(p));
    for(int i =0;i<n;i++){
        cin >> a[i];
        p[a[i]]++;
    }
    int suf[n+2];
    suf[n+1] = 0;
    for(int i = n;i>=0;i--){
        suf[i]=p[i]+suf[i+1];
    }

    int ans[n+1];
    memset(ans,0,sizeof(ans));
    int cur = 0;
    for(int i =0;i<=n;i++){
        if(p[i] == 0) break;
        int c = cur+suf[i];
        int u = p[i];
        int z = min(n, c);
        if(u <= n){ 
            ans[u]+=1;
            ans[z]-=1;
        }
        cur+=p[i]-1;
    }

    for(int i =0;i<n;i++){
        ans[i+1]=ans[i]+ans[i+1];
    }
    for(int i =0;i<=n;i++){
        cout << ans[i]+1 << " ";
    }
    cout << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
