#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n ;
    cin >> n;

    int a[n+5];
    memset(a, 0,sizeof(a));
    a[0]=1;
    int s;
    int p = 1;
    if(n%2){ 

        s=(n+1)/2;
        a[s] = p++;
        if(s%2){ 
            if(!a[s-s/2-1]) a[s-s/2-1] = p++;
            if(!a[s+s/2]) a[s+s/2] = p++;
            if(!a[s-s/2]) a[s-s/2] = p++;
            if(!a[s+s/2+1]) a[s+s/2+1] = p++;
        }else{ 
            if(!a[s-s/2]) a[s-s/2] = p++;
            if(!a[s+s/2]) a[s+s/2] = p++;

        }
       int inds[] = {1, s-s/2+1, s+1, s+s/2+2};
        while(p < n+1){
            for(int i =0;i<4;i++){ 
                if(inds[i] <= n && !a[inds[i]]){
                    a[inds[i]]=p++;
                }
                inds[i]++;
            }
        }

        for(int i =1;i<=n;i++){
            cout << a[i] << " ";
        }
    }else{
        
        s=n/2;
        a[s] = p++;
        if(s%2){ 
            if(!a[s+s/2+1]) a[s+s/2+1] = p++;
            if(!a[s-s/2-1]) a[s-s/2-1] = p++;
        }else{ 
            if(!a[s+s/2]) a[s+s/2] = p++;
            if(!a[s-s/2]) a[s-s/2] = p++;
            if(!a[s+s/2+1]) a[s+s/2+1] = p++;
        }

        int d = 0, d1 = 0;
        if(!(s%2)) d=1;
        if(s%2) d1=1;
        int inds[] = {1-d1,s-s/2+d, s+1, s+s/2+2};
        while(p < n+1){ 
            for(int i =0;i<4;i++){ 
                if(inds[i] <= n && !a[inds[i]]){
                    a[inds[i]]=p++;
                }
                inds[i]++;
            }
            
        }

        for(int i =1;i<=n;i++){
            cout << a[i] << " ";
        }
    }
    cout << endl;

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}
