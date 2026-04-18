#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[200005];
int bs(int k){ 
    int l = -1, r=n;
    while(r-l>1){ 
        int m = (r+l)/2;
        if(a[m] > k){ 
            r = m;
        }else{ 
            l = m;
        }
    }
    return l;
}
int main(){
    cin >> n >> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i =0;i<m;i++){
        int k;
        cin >> k;
        
        cout << bs(k)+1 << " ";

    }
}
