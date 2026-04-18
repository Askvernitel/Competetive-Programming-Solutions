#include <bits/stdc++.h>


using namespace std;

#define int long long

int f(int t, int a, int b, int c){ 
    int k = t/b;
    if(((t%b)+1)*a < c){ 
        k--;
        t-=((t%b)+1);
    }
    return t*a - k*c;
}
void solve(){
    int n, x;

    cin >> n >> x;

    int jump[n][3];
    int t = 0;
    int prev = -1, idx = -1;
    for(int i =0;i<n;i++){
        cin >> jump[i][0] >> jump[i][1] >> jump[i][2];
        t += jump[i][0]*(jump[i][1]-1);

        if((jump[i][0]*jump[i][1]) - jump[i][2] > prev){ 
            prev = jump[i][0]*jump[i][1] - jump[i][2];
            idx = i;
        }
    }

    int d = x-t;
    if(d <=0){
        cout << 0 << '\n';
        return;
    }
    if(prev <= 0){ 
        cout << -1 << '\n';
        return;
    }
    int a = jump[idx][0];
    int b = jump[idx][1];
    int c = jump[idx][2];

    d += a*(b-1);
    
    int g = a*b - c;
    int p = d/g;
    int left_over = d%g;
    if(a*(b-1) < left_over){
        p++;
    }
    int v = (a*(b-1))%g;
    while(((p-1)*((a*b) -c)) + (a*(b-1)) >= d){ 
        p--;
    }
    cout << p << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    int cnt = 0;
    while(tc--) {
        cnt++;
        /*if(cnt == 108){
            int n, x;
            cin >> n >> x;
            string s = "";
            s+=to_string(x);
 
            for(int i =0;i<n;i++){
                int a, b, c;
                cin >> a >> b >> c;
                s+=to_string(a);
                s+=":";
                s+=to_string(b);
                s+=":";
                s+=to_string(c);
                s+=":";
            }
            cout << s << '\n';
            continue;
        }*/
          solve();
    }
}
