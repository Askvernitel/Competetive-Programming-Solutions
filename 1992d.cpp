#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    vector<char> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    int t=m, l=k;
    for(int i=0;i<n;i++){
        while(t > 0 && i < n){
           
            t--;
            if(vec[i]=='L'){
                t = m;
            }
            if(t == 0) break;
            i++;
        }  
        
        while(i < n){
            if(vec[i] == 'C'){
                printf("NO\n");
                return;
            }
            l--;
            if(l < 0){
                printf("NO\n");
                return;
            }
            i++;
            if(vec[i] == 'L'){
                t=m;
                break;
            }
        }

    }

    printf("YES\n");
}

int main(){
    int tc;

    scanf("%d", &tc);

    while(tc--) solve();
}
