#include <bits/stdc++.h>


using namespace std;
void solve(){
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        set<int> sb;
        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        int d = n;
        
        for(int i =0;i<m;i++){
                cin >> b[i];
                sb.insert(b[i]);
        }
        if(2*m > n){
                cout << "NO\n";
                return;
        }
        sort(a, a+n);

        

        if(n%2){
                a[n/2] = INT_MAX;
                d = n-1;
        }
        sort(a, a+n);
        sort(b, b+m);
        int p = 0;
        int l = d/2 - 1;
        int r = d/2;

        cout << d << "\n";
        cout << l << " " << r << '\n';
        while(l >= 0 && r < d){ 
                auto it = prev(sb.upper_bound(a[r]));
                cout << *it << '\n';
                if(a[l] < *it){
                        cout << l << " " << r << '\n';
                        sb.erase(it);
                        r++;
                        l--;
                }else{
                        l--;
                        r++;
                }
        }
        if(sb.size() == 0){
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
