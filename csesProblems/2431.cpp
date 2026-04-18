#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main(){
    int q;
    cin >> q;

    while(q--){ 
        int k;
        cin >> k;
        int p = 9;
        int u = 9;
        int c = 1;
        int x = 1;
        while(k-u>=0){ 
            k-=u;
            c++;
            p*=10;
            x*=10;
            u=p;
            u*=c;
        }
        x--;
        int t = k/c;
        x += t;
        int v = (k)%c;
        string s = to_string(x);
        
        cout << s[v] << '\n';
            
    }
}
