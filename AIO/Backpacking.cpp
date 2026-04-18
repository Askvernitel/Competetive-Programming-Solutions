#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
void cp(map<int,int>& b, int cost, int amt){ 
    int cnt = 0;
    for(auto &[co, am]:b){ 
        if(co <= cost) cnt += am;
        else b[co] = 0;
    }
    if(k-amt < k-cnt){ 
        b[cost]+=k-amt;
        return;
    }
    b[cost] += k-cnt;
}

signed main(){
    freopen("backin.txt", "r", stdin);
   freopen("backout.txt", "w", stdout);

    cin >> n >> k;
    int d[n-1];
    int c[n];
    for(int i =0;i<n-1;i++){
        cin >> d[i];
    }

    for(int i =0;i<n;i++){
        cin >> c[i];
    }
    map<int, int> b;
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        if(b.empty()){ 
            b[c[i]]+=(k-d[i]);
            ans+=d[i]*c[i];
        }else{ 
            auto x = *b.begin();
            if(c[i] <= x.first){ 
                b.clear();
                i--;
                continue;
            }
            int cur = d[i];
            for(auto &[co, am]:b){ 
                if(co < c[i]){ 
                    if(am >= cur){ 
                        b[co] -= cur;
                        ans+=cur*co;
                        cur =0;
                        break;
                    }else{ 
                        ans+=am*co;
                        cur-=am;
                        b[co]=0;
                    }
                }else break;
            }

            if(cur > 0){
                ans += cur*c[i];
            } 
            cp(b, c[i], cur);
        }
    }
    cout << ans << '\n';
            
}
