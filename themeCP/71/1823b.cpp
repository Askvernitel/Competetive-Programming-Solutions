#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k ;
	cin >> n >> k;

	int p[n];	
	for(int i =0;i<n;i++){
		cin >> p[i];
	}
	
	set<int> b[k];	
	int t = 0;	
	for(int i =0;i<n;i++){
		if(i%k != (p[i]-1)%k){
			t++;
		}
		//b[i%k].insert(p[i]);
	}

	if(t==0){
		cout << t << '\n';
	}else if (t <= 2){ 
		cout << 1 << '\n';
	}else{
		cout << -1 << '\n';
	}


}
	
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
