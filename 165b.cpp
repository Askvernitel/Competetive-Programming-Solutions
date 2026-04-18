#include <bits/stdc++.h>

int k;
using namespace std;
int logs(int n){
    int sum = 0;
    while(n!=0){
        sum+=n;
        n/=k;
    }
    return sum;
}
int mx = 1e9, mn = 1;
int main(){
    int n;
    cin >> n >> k;
//    cout << logs(53);
    while(mn<mx) {
       int m = (mx+mn)/2;
//       cout << mn << " " << mx << endl;
       if(logs(m) >= n){
            mx = m;
       }else{
            mn = m+1;
       }
    }
    cout << mx << '\n'; 
}

