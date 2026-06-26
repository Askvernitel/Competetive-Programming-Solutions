#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
        int n;
        cin >> n;

        int h[n];
        for(int i=0;i<n;i++){
                cin >> h[i];
        }
        int w[n];
        int amounts[n];
        memset(w, 0 ,sizeof(w));
        for(int i =0;i<n;i++){

                int l = (i-1+n)%n;
                int r = i;
                int sr = r;
                int maxv = h[r]; 

                int am = 0;

                do{ 
                        int v = h[r];
                        
                        maxv = max(maxv, v);
                        w[r] = maxv;

                        r = (r+1)%n;
                }while(r != l);

                int l_maxv = h[l];
                do{
                        w[l] = min(w[l], l_maxv);
                        l_maxv = max(l_maxv, h[l]);
                        l = (l-1 + n)%n;
                }while(l != (sr-1 + n)%n);
                for(int i =0;i<n;i++){
                        am += w[i];
                }
                amounts[i] = am;
                memset(w, 0, sizeof(w));
        }

        for(int i = 0;i<n;i++){
                cout << amounts[i] << " ";
        }
        cout << '\n';
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
