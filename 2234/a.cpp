#include <bits/stdc++.h>

using namespace std;

void solve(){

        int n;
        cin >> n;

        int a[n];
        for(int i = 0;i<n;i++){
                cin >> a[i];
        }


        sort(a, a+n, greater<int>());
        for(int i = 0;i<n-2;i++){
                int d = a[i]%a[i+1];

                if(d != a[i+2]){
                        cout << -1 << "\n";
                        return;
                }
        }

        cout << a[0] << " " << a[1] << '\n';
}
int main(){
        int tc;
        cin >> tc;
        while(tc--) solve();
}
