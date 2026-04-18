#include <bits/stdc++.h>

using namespace std;

int n; 
int min_v(int arr[], int l, int r){ 
	int minv = arr[l];
	for(int i = l;i<=r;i++){
		minv = min(minv, arr[i]);	
	}
	return minv;
}
void solve(){
	cin >> n;
	int a[n], b[n];

	for(int i =0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	
	vector<pair<int,int>> ans;
	for(int i =0;i<n;i++){
		int minv1=min_v(a,i, n-1);
		int minv2=min_v(b,i, n-1);
		set<int> s1;
		for(int j=i;j<n;j++){
			if(minv1 != a[j]) continue;
			s1.insert(j);	
		}
		bool found = 0;
		int idx = 0;
		for(int j=i;j<n;j++){
			if(minv2 != b[j]) continue;
			if(s1.find(j) != s1.end()){
				found = 1;
				idx = j;
				break;
			}
		}
		if(!found){
			cout << -1 << '\n';
			return;
		}
		swap(a[i],a[idx]);
		swap(b[i],b[idx]);
		if(i == idx) continue;
		ans.push_back({i+1, idx+1});
	}
	cout << ans.size() << '\n';
	for(auto &[x, y]:ans){
		cout << x << " " << y << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
