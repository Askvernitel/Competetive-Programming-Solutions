#include <bits/stdc++.h>

using namespace std;
#define int long long
/*int arr[100001][2];
void fill(int n){ 
    for(int i =0;i<n;i++){
        arr[i][0] = 0;
        arr[i][1] = INT_MAX;
    }

}*/

int n, k, q;
int bs(int a[], int c, int t,int num){ 
    function<bool(int)> f = [&](int m){
            if(t){ 
                return (num < a[m]);
            }else{ 
                return (num < a[m]);
            }
    };

    int l = -1, r=n;

    while(r-l>1){ 
        int m = (r+l)/2;
        if(f(m)){ 
            r=m;
        }else{ 
            l=m;
        }
    }
    return ((t==0)?l:r);

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> q;
    int r[n][k];
    for(int i =0;i<n;i++){

        for(int j =0;j<k;j++){
            cin >> r[i][j];
        }
    }
    for(int i =0;i<k;i++){
        for(int j = 0;j<n-1;j++){
            r[j+1][i] = (r[j][i] | r[j+1][i]);
        }
    }
    int rev[k][n];
    for(int i =0;i<k;i++){
        for(int j = 0;j<n;j++){
            rev[i][j] = r[j][i];
        }
    }
    while(q--){
        int m;
        cin >> m;
        int hi = LLONG_MAX;
        int lo = 0;
        for(int i = 0;i<m;i++){
            int c;
            char ch;
            int num;
            cin >> c >> ch >> num;
            c--;
            int ind = ((ch == '>')? 0:1);
            if(ind) hi = min(hi, bs(rev[c], i, 0,num));
            else lo= max(lo, bs(rev[c],i,1,num));
        }
        if(lo >hi) { cout << -1 <<'\n';continue;}

        cout << lo+1 << '\n';

    }
}
