#include <bits/stdc++.h>



using namespace std;
#define int long long
vector<int> primes;
unordered_map<int, int> m;
#define M 3783
int erat[4000];
void generate_primes(int N){ 
        int d = 1;
        erat[0] = 1;
        erat[1] = 1;
        for(int i =2;i<N;i+=d,d=2){
                if(erat[i]){ 
                        continue;
                }
                for(int j = i+i;j<N;j+=i){
                        erat[j] = 1;
                }
        }
        for(int i =0;i<N;i++){
                if(!erat[i]) primes.push_back(i);
        }
        

}
void get_factors_of_lcm(int x, set<int>& facts){ 
        int d=1;
        for(int i =2;i*i<=x;i+=d, d=2){ 
                if(!(x%i)){ 
                        facts.insert(i);
                }
        }
}

void get_frequency(int* a, int n){

        set<int> lcm_factors;
        for(int i =0;i<n-1;i++){
                int l = std::lcm(a[i], a[i+1]);

                get_factors_of_lcm(l, lcm_factors);
        }

//        vector<int> lcm_factors = get_factors_of_lcm(l);

        for(int i =0;i<n;i++){
                for(int factor:lcm_factors){
                        if(a[i] < factor) break;
                        if(!(a[i]%factor)){ 
                                m[factor]++;
                                a[i]/=factor;
                        }
                        if(!(a[i]%factor)){ 
                                m[factor+factor]++;
                                a[i]/=factor;
                        }
                }
                if(a[i] > primes.back()) m[a[i]]++;
                
        }


}

signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        int a[n];
        int max_a = 0;
        for(int i =0;i<n;i++){
                cin >> a[i];
                max_a = max(a[i], max_a);
        }
        
        generate_primes(M);
        get_frequency(a, n);

        int maxv = -1;
        for(auto [k,v]:m){
                if(v < n && v > maxv){
                        maxv = v;
                }
        }

        if(maxv == -1){ 
                cout << -1 << '\n';
                return 0;
        }
        cout << n - maxv << '\n';
        return 0;
}
