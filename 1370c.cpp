#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    if(n==1){printf("FastestFinger\n"); return;}
    if(n==2){printf("Ashishgup\n"); return;}
    if(n%2){printf("Ashishgup\n"); return;}
    int m = n/2, d = 2;
    int odd = 0, even = 0;
    int p = 1, k = 1;
    for(int i = 2;i*i<=m;i++){
        if(!(m%i)){p = 0;break;}
    }
    if(p){printf("FastestFinger\n"); return;}
    while(m != 1){
        if(m%2){ k=0; break;}
        m/=2;
    }
    if(k){printf("FastestFinger\n"); return;}
    else{printf("Ashishgup\n"); return;}

    /*if(odd%2){printf("FastestFinger\n"); return;}
    else printf("Ashishgup\n");*/
}
int main(){
    int tc;

    scanf("%d", &tc);
    while(tc--) solve();
}
   
