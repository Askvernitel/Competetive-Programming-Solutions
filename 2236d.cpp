#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n, k;
        cin >> n >> k;
        int a[n];


        for(int i=0;i<n;i++){
                cin >> a[i];
        }


        map<int,int> m;
        for(int i=0;i<n;i++){
                m[a[i]]++;
        }


        for(auto it = m.rbegin();it != m.rend(); it = next(it)){
                if(!(it->second%2)){
                        cout << "YES\n";
                        return;
                }
                if(it->second%2 && next(it) != m.rend() && (((it)->first - next(it)->first) <= k)){
                        cout << "YES\n";
                        return;
                }
        }
        cout << "NO\n";
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
