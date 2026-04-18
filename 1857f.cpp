#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int ,int> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        double x, y;
        cin >> x >> y;

        double d = x*x - 4*y;
        if(d < 0){
            cout << 0 << " ";
            continue;
        }

        double p = sqrt(d);
        
        double x1 = (x+p)/2.0;
        double x2 = (x-p)/2.0;
        if(x1 != (int)x1 || x2 != (int)x2){
            cout << 0 << " ";
            continue;
        }
        if(x1 == x2){ 
            cout << (m[(int)x1]*(m[(int)x1]-1))/2 << ' ';
        }else{
            cout << m[(int)x1]*m[(int)x2] << ' ';
        }

    }

    cout << '\n';

}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
