#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> m;
	for(int i =0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
	}


	int p = n-2;
	int div=1;
	int u, v;
	while(div*div <= p){ 
		if(!(p%div)){ 
			if(div == p/div && m[div] >= 2){
				u = div;
				v = div;
				break;
			}else if(m[div] >= 1 && m[p/div] >= 1){ 
				u = div;
				v = p/div;
				break;
			}
		}
		div++;
	}
	cout << u << " " << v << '\n';


	
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
