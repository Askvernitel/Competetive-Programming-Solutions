#include <bits/stdc++.h>
#define int long long

#define OUT(l, r) cout << l << " " << r << endl
using namespace std;

void solve(){
        int n;
        cin >> n;
        int a[n]; 
        for(int i=0;i<n;i++){
                cin >> a[i];
        }

        if(n == 1) { 
                OUT(1,1);
                cout << a[0] << '\n';
                OUT(1,1);
                cout << a[0] << '\n';
                OUT(1,1);
                int val = (a[0]*3) == 0 ? 0: -(3*a[0]);
                cout << val << '\n';
                return;
        }
        int m = n-1;
        int l = 1, r = m;
        OUT(l,r);
        for(int i =0;i<m;i++){
                cout << (a[i]%n)*m << " ";
                a[i] += (a[i]%n)*m;
        }
        cout << '\n';
        l=2;
        r=m+1;
        OUT(l,r);
        for(int i =1;i<m+1;i++){
                cout << (a[i]%n)*m << " ";
                a[i] += (a[i]%n)*m;
        }
        cout << '\n';
        OUT(1,n);
        for(int i =0;i<n;i++){
                cout << -a[i] << " ";
        }

}
signed main(){
        solve();
}
