#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;

    cin >> n;

    priority_queue<int> pq;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int s = 0, cnt = 0;
    for(int i =0;i<n;i++){
        if(s + a[i] < 0 && !pq.empty()){
            if(-(pq.top()) < a[i]){
                s+=abs(pq.top()) - abs(a[i]);
                pq.pop();
                pq.push(-a[i]);
            }
        }else if(s+a[i] >= 0){
            if(a[i] < 0) pq.push(-a[i]);
            s+=a[i];
            cnt++;
        }

    }
    cout << cnt;
}
