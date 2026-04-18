#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n+1];	
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	a[n] = 1e9;
	int l=0;
	int cnt = 0;
	int o = 0;
	if(n%2){ 
		cout << -1 << '\n';
		return;
	}
	vector<pair<int,int>> v;
	for(int i =0;i<n;i++){
		if(a[i] != a[i+1]){
			v.push_back({i,i});
			v.push_back({i+1,i+1});
			i++;
		}else{
			v.push_back({i,i+1});
			i++;
		}
	}
	cout << (int)v.size() << '\n';
	for(int i =0;i<v.size();i++){
		cout << v[i].first +1<< " " << v[i].second +1<< "\n";
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
