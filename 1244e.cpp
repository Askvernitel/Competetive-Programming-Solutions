#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    sort(a,a+n);

    function<long long(long long)> f = [&](int t){ 
        int s = a[n-1]-a[0];
        int ans = 0;
        if(t >= s) return ans;
        int l = 0, r=n-1;
        int cofl=1, cofr = 1;
        while(l < r){ 
            while(a[l] == a[l+1]){
                l++;
                cofl++;
            }
            while(a[r] == a[r-1]){
                r--;
                cofr++;
            }
            if(l >= r) break;
            if(cofl <= cofr){ 
                ans+=cofl*(a[l+1]-a[l]);
                s-=(a[l+1]-a[l]);
                l++;
                if(s <= t){ 
                    ans -= cofl*(t-s);
                    return ans;
                }
                cofl++;
            }else{ 
                ans+=cofr*(abs(a[r-1]-a[r]));
                s-=abs(a[r-1]-a[r]);
                r--;
                if(s <= t){ 
                    ans -= cofr*(t-s);
                    return ans;
                }

                cofr++;
            }

        }
        return ans;

    };
    int l = 0, r = a[n-1] - a[0];
    int p = r;
    for(int i =r;i>=1;i/=2){ 
        while(p-i >= 0 && f(p-i) <= k) p-=i;
    }
    cout << p;
}
