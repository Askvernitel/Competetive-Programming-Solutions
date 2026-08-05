#include <bits/stdc++.h>


using namespace std;

void solve(){
        int n;
        cin >> n;

        char a[n];
        char b[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }
        for(int i =0;i<n;i++){
                cin >> b[i];
        }
        int mod_0=0, mod_1=0;
        for(int i =0;i<n;i++){
                if(a[i] == '1'){
                        if(i%2){ 
                                mod_1++;
                        }else{
                                mod_0++;
                        }
                }
        }

        for(int i =0;i<n;i++){
                if(b[i] == '1'){ 
                        if(i%2){ 
                                mod_1--;
                        }else{
                                mod_0--;
                        }
                }
        }
        if(mod_1 != 0 || mod_0 != 0){
                cout << "NO\n";
        }else{
                cout << "YES\n";
        }
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}
