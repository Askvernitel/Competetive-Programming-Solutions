#include <bits/stdc++.h>

using namespace std;
void solve(){
	set<int> t[24];


	int n, h, m;
	cin >> n >> h >> m;
	
	for(int i =0;i<n;i++){
		int hr, mn;
		cin >> hr >> mn;
		t[hr].insert(mn);
	}

	int cur = h;
	int j = 0;
	while(j <= 24){ 
		if(t[cur].size() != 0){ 
			if(j == 0){
				auto it = t[cur].lower_bound(m);
				if(it != t[cur].end()){
					cout << abs(h-cur) << " " << abs(m-*it) << '\n';
					return;
				}
			}else{
				int p = *(t[cur].begin());
				int tt=(((cur > h)?(cur-h):(24+cur-h)));
				int cc = ((m > p)?1:0);
				int uu = ((p>m)?p-m:60+p-m);
				if(uu == 60){uu = 0;}
				cout << tt-cc<< " " << uu << '\n'; return;
			}
		}
		cur++;
		cur%=24;
		j++;
	}
	

}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
