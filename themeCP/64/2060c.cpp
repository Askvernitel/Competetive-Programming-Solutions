#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int x[n];
	for(int i =0;i<n;i++){
		cin >> x[i];
	}
	map<int,int> m;	
	int cnt = 0;
	for(int i= 0;i<n;i++){
		if(m[x[i]] > 0){ 
			cnt++;
			m[x[i]]--;
			m[k-x[i]]--;
		}
		m[k-x[i]]++;
	}
	cout << cnt << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
