#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i =0;i<n;i++) cin >> a[i];

    int ans = 0;
    int p = a[0];
    for(int i =1;i<n;i++){
        p ^=a[i];
    }
    int m = p;
    
    ans+=m;
    for(int i =0;i<n-1;i++){
        m^=a[i];
        ans+=m;
    }
    m = p;
    for(int i =n-1;i>=0;i--){
        m^=a[i];
        ans+=m;
    }

    cout << ans;
}
