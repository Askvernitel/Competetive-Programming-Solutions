#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int const N = 5001;
int grid[N][N];
/*
bool isPrime(int x){
    if(x == 2) return true;
    for(int i =2;i*i<=x;i++)
        if(!(x%i)) return false;
    
    return true;
}*/
signed main(){
    cin >> m >> n;
    int ans =0 ;
    grid[0][0]=1;
    for(int i = 0;i<m;i++){
        for(int j =0;j<n;j++){
            if(i == 0 && j ==0) continue;
            int found = 0;
            int k =0;
            for(int v=0;v<m && k<n;v+=i){ 
                if(grid[v][k] == 0 && !found){
                    ans++;
                    found = 1;
                }
                grid[v][k] = 1;
                k+=j;
            }
        }
    }
   cout << ans;
}
