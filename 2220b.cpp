#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n, m;
        cin >> n >> m;


        int a[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        

        int cnt = 0;
        for(int i =0;i<n-1;i++){
                int j = i;
                while(i<n-1 && a[i] == a[i+1]){
                       cnt++;
                       i++;
                }
                if(cnt+1 >= m){
                        cout << "NO\n";
                        return;
                }
                cnt = 0;
        }
        cout << "YES\n";
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
