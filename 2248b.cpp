#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i =0;i<n;i++){
                cin >> a[i];
        }

        for(int i =0;i<m;i++){
                cin >> b[i];
        }
        if(2*m > n){
                cout << "NO\n";
                return;
        }
        sort(a, a+n);
        sort(b, b+m);
        int p =0; 
        while(a[p] < b[p] && a[n-m+p] > b[p] && p < m){ 
                p++;
        }
        
        if(p == m){
                cout << "YES\n";
        }else{
                cout << "NO\n";
        }

}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
