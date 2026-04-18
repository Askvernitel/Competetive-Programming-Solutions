#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	map<int,int> m;
	map<int,vector<int>> t;
	for(int i = 0;i<n;i++){
		m[a[i]]++;
	}
	for(auto &[c,d]:m){
		t[d].push_back(c);
	}
	auto p =t.rbegin();
	int ans = m.size();
	for(auto &[c,d]:t){
		for(int x:d){
			if(c <= k){ 
				k-=c;
				ans--;
			}else break;
		}
	}
	cout << max(ans,1) << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
