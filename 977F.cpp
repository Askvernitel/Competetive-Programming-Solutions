#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i =0;i<n;i++) cin >> a[i];
   
    map<int,int> m, t, c;
    for(int i =0;i<n;i++) c[a[i]]++;
    for(int i =0;i<n;i++){
        if(c[a[i]+1]>0){
            if(m[a[i]] + 1 > m[a[i]+1]){
                m[a[i]+1] = m[a[i]] + 1;
               // t[a[i]+1] = i;
            }
            
        }
        t[a[i] + 1] = i;
        c[a[i]]--;
    }
    int k = 0, f = 0;
    for(int i =0;i<n;i++){
        if(m[a[i]] > k){
            f=t[a[i]+1];
            k=m[a[i]];
        }
    }
    k++;
    int ans[k];
    ans[k-1] = f;
    for(int i = k-2;i>=0;i--){
        ans[i] = t[a[f]];
        f=t[a[f]];
    }
    sort(ans, ans+k);
    cout << k <<'\n';
    for(int i =0;i<k;i++){
        cout << ans[i] + 1 << " ";
    } 
}
