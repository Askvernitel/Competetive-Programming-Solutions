#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string x[n];
    for(int i =0;i<n;i++){
        cin >> x[i];
    }
    auto comp = [&](string a, string b){
        int p = a.size(), m = b.size();
        int l = 0, r=0;
        bool res = false;
        while(l < p || r < m){
            
            if(l<p && r <m && a[l] > b[r]){
                break;
            }else if(l<p && r < m && a[l] < b[r]){
                res = true;
                break;
            }else if(l==p && r < m && a[l-1] < b[r]){ 
                res = true;
                break;
            }else if(r==m && l < p && a[l] > b[r-1]){
                break; 
            }else if (r==m && l <p && a[l] < b[r-1]){
                res = true;
                break;
            }
            if(l != p) l++;
            if(r != m) r++;
        }
        if(l==p && r ==m && p > m) res = true;

        return res;
    };
    sort(x,x+n, comp);

    for(int i =0;i<n;i++){
        cout << x[i];
    }
}
