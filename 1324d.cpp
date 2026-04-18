#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];

    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];

    map<int, int> m;
    for(int i =0;i<n;i++){
        m[b[i]-a[i]] = (++i);
    }

    int ans = 0;
    for(int i =0;i<n;i++){
       
        auto p = m.upper_bound(a[i]-b[i]);
        cout << p->second << '\n';
        //ans+=(p!=m.end())? p->second - (i+1):m.size()-(i+1);
    }
    cout << ans;
}
