#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    
    sort(a, a+n);
    int first = 1;
    for(int i =0;i<n-1;i++){
        if(a[i] == a[i+1] && first){
            first = 0;
        }else if(a[i] == a[i+1]){ 
            
        }
    }
}
