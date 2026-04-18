#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){ 
    if(b == 0) return a;
    else{ 
        a %= b;
        return gcd(b, a);
    }

}
signed main(){
    int n, m;

    cin >> n >> m;
    int a[n];
    int minv = LLONG_MAX;
    for(int i =0;i<n;i++){
        cin >> a[i]; 
        minv = min(minv, a[i]);
    }
    int gcdd = 0;
    for(int i =0;i<n;i++){
        gcdd = gcd(a[i]-minv, gcdd);
    }

    for(int i =0;i<m;i++){
        int b;
        cin >> b;
        cout << gcd(minv+b, gcdd) << " ";

    }
}
