#include <bits/stdc++.h>


using namespace std;



int prod(vector<int> p){
        int res = 1;
        for(int d:p){
                res *= d;
        }
        return res;
}


void rec(int i, int d, vector<int>& p, set<int>& a){ 
        a.insert(d);
        if(i >= p.size()){ 
                return;
        }
        rec(i + 1, d * p[i], p, a);
        rec(i + 1, d, p, a);
}
int main(){
                 
        int a, b;


        cin >> a >> b;

        int n;

        cin >> n;

        int g = std::gcd(a, b);
        int cg = g;
        vector<int> prime_divisors_1;

        set<int> all_pos;
        for(int i =2;i*i<=g;i++){

                while(cg % i == 0){
                        prime_divisors_1.push_back(i);
                        cg /= i;
                }
        }

        if(cg != 1){ 
                prime_divisors_1.push_back(g);
        }
        
        rec(0, 1, prime_divisors_1, all_pos);




        while(n--){ 
                int l, h;
                cin >> l >> h;
                //vector<int> prime_divisors = prime_divisors_1; 


                if(g < l){ 
                        cout << -1 << "\n";
                        continue;
                }
                if(g <= h){ 
                        cout << g << "\n";
                        continue;
                }
                auto t = all_pos.upper_bound(h);
                if(all_pos.begin() == t){
                        cout << -1 << "\n";
                        continue;
                }
                if(*prev(t) >= l){
                        cout << *prev(t) << "\n";
                        continue;
                }

                cout << -1 << '\n';
                
        }
}
