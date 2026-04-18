#include <bits/stdc++.h>

using namespace std;

#define IN_RANGE(a, l, r) ((a >= l) && (a <= r))

void change_state(int* p, int a){ 
        for(int i =0;i<4;i++){
                if(p[i] == -1) continue;

                if(p[i] > a){ 
                        if(i == 0 || i == 3){
                                p[i]--; 
                        }
                }else if(p[i] < a){ 
                        if(i == 1 || i == 2){
                                p[i]++;
                        }
                }
        }
}

int calc_amount(int* p, int n, bool center, bool sides){
        int res = 0;
        if(center){
                res += (p[1] - p[0] + 1);
        }
        if(sides){ 
                if(p[2]+1>= p[3]){
                        return n;
                }
                res += (n - p[3] + 1);
                res += p[2];
        }
        int overlap = 0;
        if(center && sides){
                overlap += max(0, p[2] - p[0] + 1);
                overlap += max(0, p[1] - p[3] + 1);
        }

        if(sides){ 
                //overlap += max(0, p[2] - p[3] + 1);
        }

        return res - overlap;
}

void solve(){ 
        int n, m, q;
        cin >> n >> m >> q;


        int p[4] = {m,m,-1,-1};

        bool center = true;
        bool sides = false;
        while(q--){ 
                int a;
                cin >> a;

                if(center && sides){ 

                        change_state(p, a);
                }else if(center && !sides){ 
                        int l = p[0], r = p[1];
                        if(IN_RANGE(a, l, r)){
                                if(l == r){ 
                                        p[0] = -1;
                                        p[1] = -1;
                                        center = false;
                                }
                                p[2]=1;
                                p[3]=n;
                                sides = true;
                                cout << calc_amount(p, n, center, sides) << ' ';
                                continue;
                        }
                        change_state(p, a);

                }else if(sides && !center){

                        change_state(p, a);
                }
                
/*                cout << "L CENTER: "<< p[0] << "\n";
                cout << "R CENTER: "<< p[1] << "\n";
                cout << "L LEFT: " << p[2] <<"\n";
                cout << "R RIGHT: " << p[3] <<"\n";*/
                cout << calc_amount(p, n, center, sides) << ' ';
        }
        cout << '\n';
}
int main(){ 
        int tc;
        cin >> tc;


        while(tc--) solve();
}
