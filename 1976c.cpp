#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    int a[n+m+1], b[n+m+1];
    for(int i =0;i<n+m+1;i++) cin >> a[i];

    for(int i =0;i<n+m+1;i++) cin >> b[i];
    int preft[n+m+2][2];
    preft[0][0] = 0;
    preft[0][1] = 0;
    int types[n+m+1];
    for(int i =1;i<=n+m+1;i++){ 
        int type = (a[i-1] > b[i-1])? 0:1;
        types[i] = type;
        preft[i][type]=preft[i-1][type] + 1;
        preft[i][!type]=preft[i-1][!type];
    }

    int pref[n+m+2];
    pref[0] = 0;
    for(int i =1;i<= n+m+1;i++){
        pref[i] = pref[i-1] + max(a[i-1],b[i-1]);
    }

    int suf[n+m+2][2];
    suf[n+m+1][0]=0;
    suf[n+m+1][1]=0;
    for(int i =n+m;i>=0;i--){
        suf[i][0] = suf[i+1][0] + a[i];
        suf[i][1] = suf[i+1][1] + b[i];
    }
    function<bool(int, int)> f = [&](int idx, int mid){ 
        if(idx < mid){ 
            if(types[idx]){
                return preft[mid][0] >= n || preft[mid][1]-1 >=m;
            }else{ 
                return preft[mid][0]-1 >= n || preft[mid][1] >= m;
            }
        }
        return preft[mid][0] >= n || preft[mid][1] >= m;
    };

    for(int i =0;i<n+m+1;i++){ 
        int l = -1, r = n+m+2;

        while(r-l>1){ 
            int mid = (r+l)/2;
            
            if(f(i, m)){ 
                r = mid;
            }else{ 
                l = mid;
            }
        }
            
        int ans = 0;
        if(preft[r][0] >= n){ 
            ans+= pref[r];
            ans+= suf[n+m+2-r][0];
            if(i < r){ 
                if(types[i]){ 
                    ans-=a[i];
                }else{
                    ans-=b[i];
                }
            }else{     
                ans-=b[i];
            }
        }else{ 
            ans+= pref[r];
            ans+= suf[n+m+2-r][1];
            if(i < r){
                if(types[i]){ 
                    ans-=a[i];
                }else{
                    ans-=b[i];
                }
            }else{ 
                ans-=a[i];
            }

        }
        cout << ans << " "; 
    }
    cout << endl;
}

int main(){ 
    int tc;

    cin >> tc;

    while(tc--) solve();
}
