#include <bits/stdc++.h>


using namespace std;

int mex_of(int* mex_arr, int n){
        int i = 0;
        while(mex_arr[i] != 0 && i < n){
                i++;
        }

        return i;
}

int calc(int l, int r, int n, int* a){ 
        int m = 2*n;
        bool pal = 1;

        int mex[n];
        memset(mex, 0,sizeof(mex));
        int l1 = l, r1 = r;
        while(l <= r){
                if(a[l] != a[r]){
                        pal = 0;
                        break;
                }
                mex[a[l]] = 1;
                l++;
                r--;
        }

        if(pal){
                while(l1 >= 0 && r1 < m){ 
                        if(a[l1] != a[r1]){
                                break;
                        }
                        mex[a[l1]] = 1;
                        l1--;
                        r1++;
                }
        }


        if(!pal){
                return 1;
        }else{
                return mex_of(mex, n);
        }
}
void solve(){

        int n;
        cin >> n;

        int m = 2*n;
        int a[m];
        for(int i =0;i<m;i++){
                cin >> a[i];
        }


        int l = -1,r = -1;


        for(int i =0;i<m;i++){
                if(l == -1 && a[i] == 0){
                        l = i;
                }else if(a[i] == 0){
                        r = i;
                }
        }

        cout << max({calc(l, r, n, a), calc(l, l, n, a), calc(r, r, n, a)}) << '\n';
        
}
int main(){
        int tc;
        cin >> tc;


        while(tc--) solve();
}
