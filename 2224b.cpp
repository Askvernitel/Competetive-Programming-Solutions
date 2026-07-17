#include <bits/stdc++.h>


using namespace std;
#define int long long


int get_sorted_mex(int* a, int start_mex, int s_idx, int n){

        for(int i=s_idx;i<n;i++){
                if(start_mex == a[i]){ 
                        start_mex++;
                }
        }
        return start_mex;
}
void solve(){
        int n;
        cin >> n;
        int a[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }

        
        int maxv = a[0]; 
        int idx = 0;
        int zero_idx = -1;
        for(int i =0;i<n;i++){
                if(a[i] == 0){
                        zero_idx = i;
                }
                if(maxv < a[i]){
                        idx = i;
                        maxv = a[i];
                }
        }
        
        int mexv = 0;

        if(maxv == 1 && zero_idx != -1){
                swap(a[zero_idx], a[0]);
                sort(a+1, a+n, greater<int>());
                mexv = 1;
                int ans = mexv;
                
                for(int i =1;i<n;i++){
                
                        if(mexv == a[i]){
                                mexv++;
                        }
               //         cout << "MEXV:" << mexv << "MAXV:" << maxv << " ";
                        ans += (maxv + mexv);
                }
                cout << ans << '\n';
                return;
        }
        swap(a[idx], a[0]);
        sort(a, a+n);
        int ans = 0;
        if(maxv == 0){
        }
        mexv = get_sorted_mex(a,mexv,0,n);

        int d = ((mexv*(mexv+1))/2);
        ans += (n*maxv) + d + ((n-1-mexv )*mexv) + ((mexv == maxv+1)?1:0);

        /* 
        int last_idx = n-1; 
        for(int i =0;i<n;i++){
                int j = i;
                while(a[j] == a[j+1] && j < n-1){ 
                        j++;
                }
                for(int k = i+1;k<=j;k++){
                        swap(a[last_idx--], a[k]);
                }
                i = j;
        }
        for(int i =1;i<n;i++){
        
                if(mexv == a[i]){
                        mexv++;
                }
                //cout << "MEXV:" << mexv << "MAXV:" << maxv << "\n";
                ans += (maxv + mexv);
        }*/
        cout << ans << '\n';
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
