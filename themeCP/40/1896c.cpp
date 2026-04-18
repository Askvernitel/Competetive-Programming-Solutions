#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;

	int a[n], b[n];

	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	int ca[n];
	memcpy(ca, a, sizeof(a));
	multiset<int> sb;
	map<int,multiset<int>> mp;
	sort(a, a+n);
	sort(b, b+n);
	int p = n-x;	
	bool pos=1;
	for(int i = 0;i<x;i++){
		if(a[p] <= b[i]){ 
			pos =0;
			break;
		}
		mp[a[p]].insert(b[i]);
		p++;
	}

	for(int i = x;i<n;i++){
		sb.insert(b[i]);
	}
	for(int i = 0;i<n-x;i++){
		auto it = sb.lower_bound(a[i]);
		if(it == sb.end()){
			pos = 0;
			break;
		}
		mp[a[i]].insert(*it);
		sb.erase(it);
	}
	if(!pos){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for(int i = 0;i<n;i++){
		auto it = mp[ca[i]].begin();
		cout <<*it << " ";
		mp[ca[i]].erase(it);
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
