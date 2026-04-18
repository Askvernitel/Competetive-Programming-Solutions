#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    scanf("%lld", &n);
    
    int t = n, i = 0;
    while((t>>i)!=0){
        
        int x = (1 << i), c = (t^x);
        if(!(x & t)){i++; continue;}
        if(c < x){i--;break;}
        
        i++;
    }
    //printf("i: %d", i);
    while(i>=0){
        if(!((1<<i) & t)){i--; continue;}
        else break;
    }
    //14 1110
    vector<int> vec;
   
    if(i!=-1) vec.push_back((1<<i));

    while(i>=0){
        if(!((1<<i) & t)){i--; continue;}
        vec.push_back((t^(1<<i)));

        i--;
    }
    vec.push_back(t);
    int s = vec.size();
    printf("%lld\n", s);
    for(int i=0;i<s;i++){
        printf("%lld ", vec[i]); 
    }
    printf("\n");
} 

signed main(){
    int tc;

    scanf("%lld", &tc);

    while(tc--) solve();

}
