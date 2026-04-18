#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
        

    int a[n];

    for(int i =0;i<n;i++){
        a[i] = i+1;
    }
    swap(a[0],a[1]);
    int k = 0;
    if(n%2){ 
        k = n;
    }else{
        k = 0;
        int t = n;
        int z = 0;
        while(t != 0){ 
            k+=(1 << z);
            t = (t >> 1);
            z++;
        }
    }
    cout << k << '\n';

    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
