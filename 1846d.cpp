#include <bits/stdc++.h>

using namespace std;
void solve(){
    cout << setprecision(7) << fixed;
    double d, h;
    int n;
    cin >> n >> d >> h;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    double ans=0;
    for(int i =0;i<n;i++){
        if(i+1 < n && a[i] + h > a[i+1]){
            double p1 = a[i+1], p2= a[i];
            double base=(d-(d*(p1-p2))/h);
//                cout << base<< '\n';
            ans+=(p1-p2)*((d+base))/2;
 //           cout << (p1-p2)*((d+(d*(d-(p1-p2))/h)))/2 << '\n';

        }else{
            ans+=(h*d)/2;
        }
    }
    cout << ans << '\n';
}
int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}
