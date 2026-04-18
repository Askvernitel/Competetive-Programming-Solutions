#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];
    
    int dist[n];
    for(int i =0;i<n;i++){
        dist[i] = a[i]-b[i];
    }

}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve()
}
