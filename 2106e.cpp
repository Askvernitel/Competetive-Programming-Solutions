#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, q;
    cin >> n >> q;

    int p[n];

    for(int i =0;i<n;i++){
        cin >> p[i];
    }
    map<int,int>t;
    for(int i =0;i<n;i++){
        t[p[i]]=i;
    }

    while(q--){ 
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        if(t[k] < l || t[k] > r){cout << -1 << ' '; continue;}
        int u=n-k;
        int c=k-1;
        int d = 0;
        int f = 0;
        int v1=0, v2=0;
        while(r-l>0){ 
            int m = (r+l)/2;
            if(m > t[k]){ 
                if(k > p[m]){
                    v1++;
                }else u--;
                r=m-1;
            }else if(m < t[k]){ 
                if(k < p[m]){
                    v2++;
                }else c--;
                l=m+1;
            }else{ 
                break;
            }
        }
        int p1=v1, p2=v2;
        int z = (max(p1,p2)-min(p1,p2));
        d+=min(p1,p2)*2 + z*2;
        if((p1 > p2 && u-p2 < z) || (p2 > p1 && c-p1 < z)){ 
            cout << -1 << ' ';
            continue;
        }
        cout << d << ' ';
    }
    cout << '\n';

}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
