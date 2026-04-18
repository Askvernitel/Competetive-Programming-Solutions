#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];

    for(int i=0;i<n;i++) cin >> a[i];
    set<int> s;
    for(int i=0;i<n;i++) a[i] = a[i]%k;
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        if(a[i] != 0) s.insert(k-a[i]);
    }
    int x = 0;
    for(int i=n-1;i>=0;i--){
        if(s.find(k-a[i]) == s.end()){s.insert(k-a[i]); continue;}
        if(s.find(x) != s.end()){s.erase(x); x++;}
        if(a[i] == 0) continue;
        if(abs(k-a[i]) == x){x++; continue;}

        if(abs(k-a[i]) > x) x+=(abs(k-a[i])-x + 1);
        else x+=(abs(k-(x-abs(k-a[i]))%k) + 1);
    }
    cout << x << '\n';
}


int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
