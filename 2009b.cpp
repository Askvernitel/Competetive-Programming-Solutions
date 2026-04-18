#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    string arr[n];
    for(int i =0;i<n;i++) cin >> arr[i];

    for(int i =n-1;i>=0;i--){
        for(int j = 0;j<4;j++){
            if(arr[i][j] == '#'){
                cout << j + 1 <<" ";
            }
        }

    }
    cout << '\n';
}   

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}
