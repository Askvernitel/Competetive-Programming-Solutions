#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int,vector<int>> m;
	for(int i =0;i<n;i++){
		cin >> a[i];
		m[a[i]].push_back(i);
	}


	int t[n];
	memset(t,0,sizeof(t));
	int w=n, h=n;

	int ans[k];
	memset(ans, 0, sizeof(ans));
	int l = 0, r=n-1;
	for(auto &[c,d]:m){
		ans[c-1] = w+h;
		for(int x: d){
			t[x]=1;
		}
		while(l<r && (t[l] || t[r])){ 
			if(t[l]){
				l++; w--;h--;
			}
			if(t[r]){
				r--; w--;h--;
			}
		}
	}

	for(int i =0;i<k;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
