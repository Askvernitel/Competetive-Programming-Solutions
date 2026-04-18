#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n], b[n];
    for(int i =0;i<n;i++) scanf("%d", &a[i]);
    for(int i =0;i<n;i++) scanf("%d", &b[i]);
    int ans = 0;
    for(int i =0;i<n;i++){
        if(b[i]){ 
            ans+=a[i];
            a[i] = 0;
        }
    }
    int l = 0, r=0, s=0, t=0;
    while(r < n){
        if(r-l< k){
            t+=a[r];
            r++;
        }else{
            s = max(s,t);
            t -= a[l];
            l++;
        }
        s=max(s,t);

    }
    ans+=s;
    printf("%d",ans);
}
