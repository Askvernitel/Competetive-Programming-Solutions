#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[100001];
int bs(int x){
    int l = 0, r=n;

    while(l<r){
        int mid = l + (r-l)/2;
        if(a[mid]<=x){
            l = mid+1;
        }else{
            r = mid;
        }
    }
     
    return l;
}
int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> n >> q;

    for(int i =0;i<n;i++) cin >> a[i];

    sort(a, a+n);
    
    while(q--){
        int l,r;
        cin >> l >> r;
            
        cout << max(bs(r) - bs(l-1), 0)<< '\n';
    }   

}
