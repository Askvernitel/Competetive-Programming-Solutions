#include <bits/stdc++.h>

using namespace std;

int main(){
    int inf = 1e9+7;
    int n;
    cin >> n;
    
    int a[n], f[n+2];
    for(int i=0;i<n;i++) cin >> a[i];
    
    
    for(int i =0;i<n+2;i++){
        f[i] = inf;
    }
    f[0] = 0;

    for(int i =0;i<n-1;i++){
        f[i+1] = min(f[i+1], f[i] + abs(a[i+1]-a[i]));
        if(i+2 < n) f[i+2] = min(f[i+2], f[i] + abs(a[i+2]-a[i])); 
    }
    cout << f[n-1];
}
