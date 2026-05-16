#include <bits/stdc++.h>

#define OUT(a) cout << a << '\n';

using namespace std;


void bit_map(int a){ 
        string s = "";
         
        while(a > 0){ 
                int t = a & 1;
                s+=to_string(t);


                a >>=1;
        }
        
        OUT(s);
}
void solve(){ 
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0;i<n;i++){
                cin >> a[i];
        }
        int ans = 0;

        for(int i =0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        ans = max(a[i]^a[j], ans);
                }
        }
        cout << ans << '\n';


//       cout << ans << "\n";
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
