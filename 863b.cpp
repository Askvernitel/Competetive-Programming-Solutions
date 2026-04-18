#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int m = 2*n;
    int a[m];
    for(int i =0;i<m;i++) cin >> a[i];

    sort(a, a+m);
    int ans = INT_MAX;
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m; j++){
            int b[m-2];
            int p = 0;
            for(int k =0;k<m;k++){
                if(k == i || k == j) continue;
                b[p] = a[k];
                p++; 
            }
            int d = 0;

            for(int k =0;k<m-2;k+=2){
                d+=abs(b[k]-b[k+1]);
            }
            ans = min(d, ans);
        }

    }
    cout << ans;
    
}
