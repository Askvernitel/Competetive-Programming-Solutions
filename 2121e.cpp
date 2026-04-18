#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    int p = r-l;
    int cc = p;
    int u = 0;
    int ll = 0;
    int tt = 0;
    while(p != 0 ){
        int c = p%10;
        p/=10;
        ll++;
        if(p == 0 && c == 1){ 
            break;
        }
        tt++;
    }
    string ls, rs;
    while(l != 0){
        ls.push_back((l%10) + 48);
        l/=10;
    }
    while(r != 0){
        rs.push_back((r%10) + 48);
        r/=10;
    }
    reverse(ls.begin(), ls.end());
    reverse(rs.begin(), rs.end());
    int n = ls.size();
    int ans = 0;
    int j =0;
    while(j<n && ls[j] == rs[j]){
        j++;
        ans+=2;
    }
    int p1 = ans;
    int p2 =ans;
    if(rs[j] - ls[j] == 1){
        int t = j;
        p1++;p2++;
        t++;
        while(t<n){
            if(ls[t] != '9') break;
            if(ls[t] == '9'){
                p1++;
            }
            t++;
        }
        t=j+1;
        while(t<n){
            if(rs[t] != '0') break;
            if(rs[t] == '0'){ 
                p2++;
            }
            t++;
        }
    }
    cout << min(p1,p2) << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
