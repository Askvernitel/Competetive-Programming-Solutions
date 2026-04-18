#include <bits/stdc++.h>

using namespace std;
int const N = 200001;
int arr[N];

int log3(int a){ 
    int ans = 0;
    while(a != 0){
        a/=3;
        ans++;
    }
    return ans;
}
void fill(){
    arr[1] = log3(1);
    for(int i =2;i<N;i++){
        arr[i] = arr[i-1] + log3(i);
    }
}
void solve(){
    int l, r;
    cin >> l >> r;
    //cout << arr[r]-arr[l-1];
    int ans =arr[r]-arr[l-1] + log3(l);
    cout << ans << '\n';
}

int main(){
    int tc;
    fill();
    cin >> tc;

    while(tc--) solve();
}
