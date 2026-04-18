#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n;
    cin >> n;

    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    sort(a, a+n);
    int ans = 1;
    for(int i =0;i<n;i++){
        int t = 1;
        int amount = 1;
        for(int j = i;j<n-1;j++){
            if(a[j]+t < a[j+1]){
                break;
            }
            int p = j, cnt=0;
            while(j+1 < n && a[p] + t >= a[j+1]){j++; cnt++;}
            j--;
            amount+=cnt;
            t++;
    } int p = 1;
        for(int j = i;j>0;j--){
            if(a[j]-p > a[j-1]){
                break;
            }
            int p = j;
            int cnt =0;
            while(j-1 >= 0 && a[p] - t <=a[j-1]){j--;cnt++;}
            j++;
           
            amount+=cnt;
            p++;
        }
        ans = max(ans, amount);
    }
    cout << ans;
}
