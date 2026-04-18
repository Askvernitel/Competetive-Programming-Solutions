#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("tracing.in", "r", stdin);
   freopen("tracing.out", "w", stdout);
    int n, t;
    cin >> n >> t;

    string str;
    cin >> str; 
    vector<int> a[t];

    for(int i = 0;i<t;i++){
        int T, x, y;
        cin >> T >> x >> y;
        a[i].push_back(T); a[i].push_back(x); a[i].push_back(y);
    }
    sort(a, a+t);
    int lb = t, ub = 0;
    int posc[n];
    memset(posc, 0, sizeof(posc));
    for(int i = 0;i<=t;i++){

        for(int j = 0;j<n;j++){
            int ks[n];
            memset(ks, 0, sizeof(ks));
            
            string s(n, '0');
            s[j] = '1';
            ks[j] = i;
            for(int k = 0;k<t;k++){
                /*for(int v=0;v<n;v++){
                    if(ks[v] == 0) s[v] = '0';
                }*/
                int c1=a[k][1], c2=a[k][2];
                int nks1, nks2;
                nks1 = ks[c1-1]; nks2 = ks[c2-1];
                if(ks[c1-1]) ks[c1-1]--;
                if(ks[c2-1]) ks[c2-1]--;
                if(nks1 && s[c2-1] == '0'){s[c2-1] = '1'; ks[c2-1] = i;}
                if(s[c1-1] == '0' && nks2){s[c1-1] = '1'; ks[c1-1] = i;}
               // if(ks[c1-1] && ks[c2-1]){ks[c1-1]--; ks[c2-1]--;}  
                /*for(int v=0;v<n;v++){
                    if(ks[v] != -1) ks[v] -=1;
                }*/
            }

            if(s == str){
                lb = min(lb, i);
                ub = max(ub, i);
//                cout << i << " ";
  //              cout << j << '\n' ;
                posc[j]=1;
            }
        }
    }
    int cnt = 0;
    for(int i =0;i<n;i++){
        if(posc[i]) cnt++; 
    }
    cout << cnt << " ";
    
    cout << lb << " ";
    if(ub == t) cout << "Infinity";
    else cout << ub;
}
