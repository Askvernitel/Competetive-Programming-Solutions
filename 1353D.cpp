#include <bits/stdc++.h>
#include <queue>

using namespace std;



void solve(){
        int n;
        cin >> n;
        int a[n]; 
        priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
        pq.push({{n, 0}, {0,n-1}}); 
        int cnt = 0;
        while(!pq.empty()){
                cnt++;
                pair<pair<int,int>,pair<int,int>> t = pq.top();
                int l = t.second.first;
                int r = t.second.second;
                pq.pop();
                int m = (r+l)/2;
                if(l > r){
                        break;
                }
                a[m] = cnt;
                pq.push({{(r-(m+1)), n-(m+1)}, {m + 1, r}});
                pq.push({{((m-1)-l), n-l}, {l, m - 1}});
        }
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
