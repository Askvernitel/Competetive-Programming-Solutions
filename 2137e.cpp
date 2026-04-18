#include <bits/stdc++.h>

#define int long long
using namespace std;


int mex(int* a, int len){ 
        sort(a, a+len);
        int mex=0;
        for(int i=0;i<len;i++){
                if(a[i] == mex){
                        mex++;
                }
        }
        return mex;
}

int min_dup(int* a, int len){ 
        int d[len+1];
        memset(d, 0, sizeof(d));
        for(int i=0;i<len;i++){
                d[a[i]]++;
        } 

        for(int i=0;i<=len;i++){
                if(d[i] > 1){ 
                        return i;
                }
        }
        return mex(a, len);
}


void solve(){
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> s;
        for(int i=0;i<n;i++){
                cin >> a[i];
                s[a[i]]++;
        }


        int minv = min_dup(a, n);
        int mexv = mex(a, n);

        int converge_val = min(minv, mexv);
        
        for(int i = 0;i<n;i++){
                if(s[a[i]] > 1 || a[i] > mexv){
                        a[i] = mexv;
                }
        }
        int sum = 0; 
        if(k > 1){ 
                int cnt = 0;
                for(int i =0;i<n;i++){
                        if(a[i] >= converge_val){ 
                                cnt++;
                        }
                }
                for(int i =0;i<n;i++){
                        if(converge_val > a[i]){ 
                                sum += a[i];
                        }
                }
                if(cnt > 1){
                        if(mexv > converge_val ){ 
                                sum += ((k-2)%2)*cnt;
                        }else{
                                sum += ((k-1)%2)*cnt;
                        }
                }
                sum += cnt*converge_val;

                cout << sum << '\n';
                return;
        }

        for(int i =0;i<n;i++){
                sum += a[i];
        }
        cout << sum << '\n';
}
signed main(){ 
        int tc;
        cin >> tc;

        while(tc--) solve();
        
}
