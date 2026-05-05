#include <bits/stdc++.h>

using namespace std;



bool verify(string& x){
        int sz = x.size();
        bool is_even = 1;
        bool superpos = 0;
        bool a_added = 0, b_added = 0;
        for(int i =(sz-1);i>=0;i--){
                if(superpos){ 
                        superpos=0;
                        continue;
                }
                if(is_even){
                        if(x[i] == 'a'){ 
                                a_added = 1;
                        }else if(x[i] == 'b'){
                                b_added = 1;
                        }else if(x[i] == '?'){ 
                                a_added = 1;
                                b_added = 1;
                        }
                } else{
                        if(x[i] == 'a' && !is_even && b_added){
                                a_added = 0;
                                b_added = 0;
                        }else if(x[i] == 'b' && !is_even && a_added){
                                a_added = 0;
                                b_added = 0;
                        }else if(x[i] == '?' && !is_even){
                                if(is_even){ 
                                        superpos=1;
                                }
                                a_added = 0;
                                b_added = 0;
                        }else if(!is_even){
                                return false;
                        }
                }

                is_even = !is_even;
        }
        if(b_added && !a_added){ 
                return false;
        }
        return true;
}

void solve(){
        int n;
        cin >> n;
        char a[n];
        for(int i =0;i<n;i++){
                cin >> a[i];
        }

        string s = string(a,n);
        if(verify(s)){ 
                cout << "YES\n";
        }else{ 
                cout << "NO\n";
        }

}
int main(){ 
        int tc;
        cin >> tc;

        while(tc--) solve();
}
