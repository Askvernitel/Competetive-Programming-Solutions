#include <bits/stdc++.h>

using namespace std;

int f(int ){

}
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    if(a[n-1] < a[n-2]){ 
        cout << -1 << '\n';
        return;
    }
    int max_diff = a[n-1] - a[n-2];

    for(int i = n-3;i>=0;i--){ 
        int diff = a[i] - a[i+1];
        if(diff > 0){ 
            
        }
    }
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
