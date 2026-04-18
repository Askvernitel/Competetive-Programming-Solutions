#include <bits/stdc++.h>

using namespace std;

bool check (map<int,int>& t, int l, int r){

    auto it1 = t.lower_bound(r);
    if(it1 == t.end()){ 
        return false;
    }
    if(it1->second <= l){ 
        return true;
    }
    return false;
    //auto it2 = prev(t.lower_bound(l));

    /*if(it2 == t.end() || it1 == t.end()){
        return false;
    }
    return true;*/
}
void solve(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int l = 0;

    map<int,int> t;
    for(int r =1;r<n;r++){

        if(a[r] != a[r-1]){ 
            if(r == n-1){ 
                t[r]=l;
            }
            continue;
        }
        t[r-1]=l;
        l=r;
    }
    int pref[n+1];
    pref[0] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = pref[i-1]+a[i-1];
    }

    int suf[n+1];
    suf[n] = 0;
    for(int i =n;i>=0;i--){
        suf[i-1] = suf[i] + a[i-1];
    }


    while(q--){ 
        int ans = 0;
        int l, r;
        cin >> l >> r;
        l--; r--;
        if((r-l+1)%3 != 0){ 
            cout << -1 << '\n';
            continue;
        }
        if(check(t, l,r)){
            ans++;
        }
        int k = pref[r+1]-pref[l];
        if(k%3 != 0){ 
            cout << -1 << '\n';
            continue;
        }
        ans+=(r-l+1)/3;
        cout << ans << '\n';
    }

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
