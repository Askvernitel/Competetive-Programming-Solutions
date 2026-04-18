#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >>n;

	int a[n], b[n];
	map<int,int> mb, ma;
	for(int i =0;i<n;i++){
		cin >> a[i];
		ma[a[i]]=i;
	}
	for(int i =0;i<n;i++){
		cin >> b[i];
		mb[b[i]]=i;
	}
	int cnt =0;
	int idx =-1;
	for(int i = 0;i<n;i++){
		if(a[i] == b[i]){
			cnt++;
			idx=i;
		}
	}
	if(cnt > 1 && n%2){
		cout << -1 << '\n';
		return;
	}
	if(cnt > 0 && !(n%2)){
		cout << -1 << '\n';
		return;
	}
	vector<pair<int,int>> vec;
	if(cnt != 0 && n/2 != idx){ 
		ma[a[idx]] = n/2;
		ma[a[n/2]] = idx;
		mb[b[idx]] = n/2;
		mb[b[n/2]] = idx;
		swap(a[idx],a[n/2]);
		swap(b[idx],b[n/2]);
		vec.push_back({idx, n/2});
	}
	for(int i = 0;i<n;i++){
		if(a[n-i-1] != b[i]){
			int p1 =mb[a[n-i-1]];
			mb[b[p1]]=i;
			mb[b[i]]=p1;
			ma[a[p1]]=i;
			ma[a[i]]=p1;
			swap(b[p1], b[i]);
			swap(a[p1], a[i]);
			vec.push_back({i,p1});
		}
	}

	for(int i = 0;i<n;i++){
		if(a[n-i-1] != b[i]){
			cout << -1 << '\n';
			return;
		}
	}
	cout << vec.size() << '\n';
	for(int i=0;i<vec.size();i++){
		cout << vec[i].first+1 << " " << vec[i].second +1<< '\n';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
