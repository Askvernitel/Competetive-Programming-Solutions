#include <bits/stdc++.h>

using namespace std;
void d(vector<int>& a,int n ){
    
    while(n !=0){
        a.push_back(n%10);
        n/=10;
    }
}

int main(){
    int inf = 1e9;
    int n;
    cin >> n;
    
    int f[n+1];
    for(int i =0;i<n+1;i++){
        f[i]=inf;
    }
    
    f[n]=0;
    for(int i =n;i>=0;i--){ 
       // if(f[i] == inf) continue;
        vector<int> a = {};
        d(a,i);
        int m = a.size();
        for(int j = 0;j<m;j++){
            if(i-a[j] >= 0){
                f[i-a[j]]=min(f[i]+1, f[i-a[j]]);
            }
        }
        
    }
    
    cout << f[0]; 

}
