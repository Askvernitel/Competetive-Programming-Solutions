#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    priority_queue<int> pq;
    int ans =0;
    for(int i =0;i<n;i++){
        if(pq.empty()){
            pq.push(a[i]);
            continue;
        }
        int t=pq.top();
        while(t > a[i]){ `
            ans++;
            pq.pop();
            if(t%2){
                pq.push(t/2); pq.push(t/2 + 1);
            }else{
                pq.push(t/2); pq.push(t/2);
            }
            t=pq.top();
        }
        pq.push(a[i]);
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}
