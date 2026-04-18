#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];

	pair<int,pair<int,int>> d[n];
	for(int i =0;i<n;i++){
		d[i].first=(a[i]-1)+(b[i]-1);
		d[i].second.first=a[i];
		d[i].second.second=b[i];
	}

	sort(d,d+n);

	for(int i =0;i<n;i++){
		cout << d[i].second.first<< " ";
	}
	cout << '\n';
	for(int i =0;i<n;i++){
		cout << d[i].second.second<< " ";
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
