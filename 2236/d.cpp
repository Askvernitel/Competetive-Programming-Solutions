#include <bits/stdc++.h>

using namespace std;

void solve(){
        int n, k;
        cin >> n >> k;

        int a[n];

        for(int i=0;i<n;i++){
                cin >> a[i];
        }

        map<int,int> s;
        for(int i =0;i<n;i++){
                s[a[i]]++;
        }

        sort(a, a+n, greater<int>());
        int prev = INT_MAX;
        int was_odd = 0;
        int amt = 0;

        int f = 0; 
        for(int i =0;i<s.size();i++){ 
                int d = s[a[i]];

                if(prev - a[i] <= k ){
                        amt++;
                }else{ 
                        amt = 0;
                }
                if(d%2 && (prev - a[i]) <= k){ 
                        cout << "YES\n";
                        return;
                }

                if(!(d%2)){ 
                        cout << "YES\n";
                        return;
                }

                prev = a[i];
/*
                if(prev - c > k && d%2){
                        was_odd = 1;
                }else if(was_odd && !(d%2) && prev - c <= k){
                        was_odd = 1;
                }

                if(d%2){ 
                        was_odd = 1;
                }*/
        }
        cout << "NO\n";
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();

}
