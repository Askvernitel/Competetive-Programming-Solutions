#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    sort(a, a+n);
    int i =0;
    set<int> p;
    while(i<n){
        if(i+3<n && a[i] == a[i+3]){
            cout << "YES\n";
            return;
        }
        if(i+2 < n && a[i] == a[i+2] && p.find(a[i]) != p.end()){
            cout << "YES\n";
            return;
        }
        if(i+1 < n && a[i] == a[i+1] && p.find(a[i]) != p.end()){
            cout << "YES\n";
            return;
        }
        if(i+2<n && a[i] == a[i+2]){
            p.insert(a[i]+1);
            i=i+3;
            continue;
        }
        if(i+1< n && a[i] == a[i+1]){
            p.insert(a[i]+1);
            i=i+2;
            continue;
        }
        if(p.find(a[i]) != p.end()){
            p.insert(a[i]+1);
        }
        i++;
    }
    cout << "NO\n";
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
