#include <bits/stdc++.h>
#define int long long
using namespace std;
int const N=40;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int odd=0,d=0;  
    for(int i =0;i<n-1;i++){
        if(a[i]%2 || a[i+1]%2) odd=1;
        if(a[i] != a[i+1])d=1;
    }
    if(odd && d){cout << -1 << '\n'; return;}
    vector<int> ans(N);
    int t = -1;
    for(int i =0;i<n;i++){
        if(a[i]!=0){t=a[i]; break;}
    }
    if(t ==-1){cout << 0<< '\n'; cout << '\n'; return;}
    for(int i =0;i<n;i++){
        a[i] = abs(a[i]-t);
    }
    ans[0] =t;
    int c=1, p = 0;
    for(int i=1;i<N;i++){
        int k = -1;
        for(int j=0;j<n;j++){
            if(a[j]!=0){
               k = j;
               break;
            }
        }
        if(k==-1){p=1; break;} 
        if(c>N){break;}
        int x = a[k]/2;
        
        for(int j=0;j<n;j++){
            a[j] = abs(a[j]-x);
            a[j] = abs(a[j]-x);
        }
        ans[i] = x;
        i++;
        c++;
        if(c > N){break;}
        ans[i] = x;
        c++;
    }
    if(p && c <= N){
        cout << c << '\n';
        for(int i =0;i<c;i++){
            cout << ans[i] << " ";
        }
    }else{
        cout << -1;
    }
    cout << '\n';
}
signed main(){
//    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--) solve();
}
