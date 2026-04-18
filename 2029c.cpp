#include <bits/stdc++.h>

using namespace std;
int n;
int a[300001];
int cache[300005][3];
int op(int rating, int cur){
    if(rating <= cur) return rating + min(1,cur-rating);
    return rating-1;
}
int rec(int i, int skip){
    if(i == -1){
        return 0 ;
    }
    if(cache[i][skip] != -1){ 
        return cache[i][skip];
    }

    if(skip == 0){ 
        cache[i][skip] = op(rec(i-1, skip), a[i]);
        rec(i-1, 1);
        rec(i-1, 2);
    }
    if(skip == 1){
        cache[i][skip] = max(rec(i-1,0), rec(i-1,1));
    }
    if(skip == 2){ 
        if(i == 0){ 
            cache[i][skip]=0;
        }else
        cache[i][skip] = max(op(rec(i-1,1), a[i]), op(rec(i-1,2),a[i]));
    }
    return cache[i][skip];
}

void solve(){
    cin >> n;

    for(int i =0;i<n;i++) cin >> a[i];
    for(int i = 0;i<n+1;i++){
        cache[i][0] = -1;
        cache[i][1] = -1;
        cache[i][2] = -1;
    }
//    cout << rec(n-1,0) << '\n';
    rec(n-1,0);
    rec(n-1,1);
    rec(n-1,2);

    cout << max(cache[n-1][2], cache[n-1][1]) << '\n';
 /*   
    for(int i = 0;i<=n+1;i++){
        cout << cache[i][0] << " " << 
        cache[i][1] << " " << 
        cache[i][2] << '\n';
    }*/
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
