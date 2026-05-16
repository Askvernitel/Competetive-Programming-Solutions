#include <bits/stdc++.h>


using namespace std;


vector<pair<int,int>> factors;
void get_factors(int n){
        int d = 1; 
        for(int i = 2; i*i <= n; i+=d, d=2){ 
                if(!(n%i)){ 
                        factors.push_back({i, 0});

                        while(!(n%i)){ 
                                n/=i;
                                factors.back().second++;
                        }
                }
        }

        if(n != 1) factors.push_back({n, 1});
}

int main(){ 
        int n;
        cin >> n;

        get_factors(n);


        for(const pair<int,int> fact:factors){ 
                cout << "Factors: " << fact.first << " " << fact.second <<'\n';
        }
}
