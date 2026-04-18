#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int p[n];
    
    string s;
    for(int i =0;i<n;i++) cin >> p[i];
    cin >> s;
    
    int arr[n+1], b[n+1];
    memset(arr, 0, sizeof(arr));
    memset(b, -1, sizeof(b));
    for(int i =0;i<n;i++){
        int cnt = 0;
        int q = i;
        int k = p[i];
        while(!arr[k]){
            if(s[q] == '0') cnt++;
            arr[k] = 1;
            q = k-1;
            k = p[k-1];
        }
         k = p[i];
        while(b[k]==-1){
            b[k] = cnt;
            k = p[k-1];
        }
    }
    for(int i =1;i<n+1;i++){
        cout << b[i] << " ";
    }
    cout << '\n';
}


int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();

}
