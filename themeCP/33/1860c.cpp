#include <bits/stdc++.h>

using namespace std;

int n;
void solve(){
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	map<int,int> m;

	int s[n];
	int ans = 0;
	for(int i =0;i<n;i++){
		auto it = (m.lower_bound(a[i]));
		if(m.size() == 0 || it == m.begin()){ 
			m[a[i]] = 1;
		}else{ 
			m[a[i]]=m[prev(it)->second]+1;
			if(!(m[a[i]]%2)){
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
