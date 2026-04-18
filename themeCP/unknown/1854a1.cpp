#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];

	bool neg = 1;
	int idx = -1;
	for(int i =0;i<n;i++){
		if(a[i] > 0){
			neg = 0;
			idx = i;	
		}
	}
	vector<pair<int,int>> ans;
	if(neg){ 
		for(int i =0;i<6;i++){
			a[n-1] += a[n-1];
			ans.push_back({n, n});
		}
		
		for(int i =n-1;i>0;i--){
			if(a[i-1] > a[i]){
				a[i-1] += 2*a[i];
				ans.push_back({i, i+1});
				ans.push_back({i, i+1});
			}
		}
	}else{
		for(int i =0;i<6;i++){
			a[idx] += a[idx];
			ans.push_back({idx+1, idx+1});
		}
		a[0]+=a[idx];
		ans.push_back({1, idx+1});
		for(int i =0;i<n-1;i++){
			if(a[i+1] < a[i]){
				a[i+1]+=2*a[i];
				ans.push_back({i+2, i+1});
				ans.push_back({i+2, i+1});
			}
		}
	}
	cout << (int)ans.size() << '\n';
	for(int i =0;i<(int)ans.size();i++){
		cout << ans[i].first << " " << ans[i].second << '\n';
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
