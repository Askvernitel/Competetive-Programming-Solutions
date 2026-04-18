#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int m,n;
    cin >> m;
    int a[m];
    int sum = 0;
    set<int> s;
    for(int i =0;i<m;i++){
        cin >> a[i];
        sum+=a[i];
        s.insert(a[i]);
    }
    cin >> n; 
    int b[n];
    for(int i =0;i<n;i++){
        cin >> b[i];
        s.insert(b[i]);
    }
    int prev =0;
    for(int x:s){ 
        if(x-prev != 1) break;
        prev = x;
    }
    cout << prev << '\n';
    cout << sum-((prev*(prev+1))/2) -1;

}
