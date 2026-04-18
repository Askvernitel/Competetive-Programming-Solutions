#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second


void solve(){
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].F >> a[i].S;
    }
    sort(a, a+n);
    vector<int> v;
    int ans =0;
    for(int i =0;i<n;i++){
        pair<int,int> p =a[i];
        v.push_back(p.S);
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
