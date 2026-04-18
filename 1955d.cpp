#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    int a[n];
    map<int,int> b;

    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<m;i++){
        int num; cin >> num;
        b[num]++;
    }

    /*int pref[n+1];
    pref[0] =0;
    for(int i = 1;i<n+1;i++) pref[i] = pref[i-1] + a[i];*/
    map<int,int> c;
    int l = 0, r=m-1, cnt =0, ans=0;
    for(int i =l;i<m;i++){c[a[i]]++; if(b.find(a[i]) != b.end() && b[a[i]] >= c[a[i]]){
            cnt++;
        }
    }
//    cout << cnt << '\n';
    for(int i =1;i<=n-m+1;i++){
        if(cnt >= k) ans++;
        c[a[i-1]]--;
        if(c[a[i-1]] < b[a[i-1]]){cnt--;}
        r = i+m-1;
        c[a[r]]++;
        if(b.find(a[r]) != b.end() && b[a[r]] >= c[a[r]]){
            
            cnt++;
        }
    }
    cout << ans << '\n';

}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
