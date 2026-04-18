#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    

    int a[n+1];
    int f[n], t[n];
    a[n] = -1;
   
    bool b[n];
    memset(f, 0, sizeof(f));
    for(int i =0;i<n;i++) cin >> a[i];
    int s=0, cnt = 1, mx = 0;
    for(int i =0;i<n;i++){
        //b[s] = 1;
        f[i] = cnt;
        if(a[i] >= a[i+1]){
            for(int j = s;j<i+1;j++){
                t[j] = cnt;
            }
            f[i+1] = 1;
            cnt=0;
            s=i+1;
        }
        cnt++;
        mx = max(cnt,mx);
    }

    if(!f[n-1]) f[n-1] = cnt;

   /* for(int i =0;i<n;i++){
        cout << t[i] << " "; 
    }*/
    for(int i = 1;i<n-1;i++){
        if(a[i-1] < a[i+1]){

            if(a[i+1] > a[i]){
                mx = max(t[i+1] - f[i] + f[i-1], mx);
            }else{
                mx = max(t[i+1] + f[i-1], mx);
            }
        }
    }
    cout << mx;
}
 
