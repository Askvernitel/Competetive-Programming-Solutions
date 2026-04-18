#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    
    int s = 0;

    for(int i =n;i>0;i--){
        s += (2*i - 1) * i;
    }

    cout << s << " " << 2*n-1 << '\n';

    for(int i =n;i>=1;i--){
        cout << 1 << " " << i << " ";
        for(int j=1;j<n+1;j++){
            cout << j << " ";
        }
        cout << '\n';
        if(i > 1){
        cout << 2 << " " << i-1 << " ";
        for(int j=1;j<n+1;j++){
            cout << j << " ";
        }
        cout << '\n';}
    }

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
