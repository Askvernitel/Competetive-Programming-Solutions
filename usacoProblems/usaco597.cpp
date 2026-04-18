#include <bits/stdc++.h>

using namespace std;


int ind=1, max_gap = 0;
double bs(int t, function<bool(double, int)> f){
    double k = 1;
    double diff = 0.1;
    for(int i = t; i>=1; i/=2){
        while(!f((double)k+i, ind)) k += i;
    }
    while(!f(double(k+diff), ind)){
        k +=diff;
    }
    return k+diff;

}


int main(){
//freopen("angry.in", "r", stdin);
//freopen("angry.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    sort(a, a+n);
    for(int i =0;i<n-1;i++){
        if(max_gap < a[i+1] - a[i]){
            ind = i;
            max_gap=a[i+1]-a[i];
        }   
    }

    function<bool(double, int)> check = [&](double x, int k){ 
        int lval = a[k], rval = a[k+1];
        int l = k, r = k + 1;
        int pos = 1;
        double cur = x;
        if(a[l+1] - a[l] > 2.0*cur) return false;
        cur--;
        
        while(l > 0 || r < n-1){
            if((l > 0 && a[l] - a[l-1] > cur) || (r < n-1 && a[r+1] - a[r] > cur)){
                pos = 0; break;
            }
            l--; r++;
            cur--;
        }

        return (bool)pos;
    };
    cout << setprecision(1)<<fixed;
    cout << (double)bs(1e9, check);


}
