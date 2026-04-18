#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    map<int,int> m;
    int sum = 0;
    int cnt =0;
    int ans = 0;
    for(int i =0;i<n;i++){
        sum+=a[i];
        ans+=m[(abs((sum%n+n)%n))];
        if(sum%n == 0) ans++;
        m[abs((sum%n+n)%n)]++;
    }
    cout << ans << '\n';
 
}
