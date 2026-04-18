#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    string s("",m);
    for(int i =0;i<m;i++) s[i] = 'B';

    for(int i =0;i<n;i++){
        int idx = a[i]-1;
        int min_idx = min(idx, m - idx-1);
        int max_idx = max(idx, m - idx-1);
        if(s[min_idx] == 'B'){ 
            s[min_idx] = 'A';
        }else if(s[max_idx] == 'B'){
            s[max_idx] = 'A';
        }
    }
    cout << s << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
